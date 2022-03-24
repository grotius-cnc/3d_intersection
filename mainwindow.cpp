#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Geom_Circle.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom_Line.hxx>
#include <Geom_Curve.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <gp_Pnt.hxx>
#include "functions/ArcCenter.h"
#include "functions/LineSphere.h"
#include "functions/LineLine.h"
#include "functions/PointPlane.h"
#include "functions/LineShape.h"
#include "functions/SplineShape.h"
#include "functions/ArcShape.h"

//! Creator : Skynet Cyberdyne.
//! Date    : 01-2021.
//!
//! The occt_viewer widget has it's own opengl interface, separated from qt opengl to
//! avoid opengl entanglement.
//!
//! This widget has several implementation examples:
//!
//! 1. Xyz mouse coordinates mapped to the occt environment.
//! 2. Transparant qt widget overlay.
//! 3. Viewports, 3d, top, bottom, left, right, front, back.
//! 4. Zoom to fit, zoom +, zoom -
//! 5. Create a shape and set tranceparancy level.
//! 6. Show shapes as wireframe or as shaded object.
//! 7. Show or hide 3d navigation box.
//! 8. Show or hide triedron.
//! 9. Show shape in orthographic or perspective mode.
//! 10. Show or hide shape boundary lines.
//! 11. Print the actual opencascade performance.. // OcctQtViwer::show_specs;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! Add the occt_viewer widget.
    QGridLayout *layout=new QGridLayout(occt_viewer);
    //! Add the occt_control widget.
    layout->addWidget(occt_controls,0,0,Qt::AlignCenter);
    ui->gridLayout->addWidget(occt_viewer);

    const QColor color= ui->centralwidget->palette().color(QPalette::ColorRole::Window);
    occt_viewer->set_backgroundcolor(color.red(),color.green(),color.blue());

    connect(timer, &QTimer::timeout, this, &MainWindow::mainloop);
    timer->start(50);

    connect(occt_controls, &OcctQtControls::toolButton_intersect_pressed, this, &MainWindow::on_toolButton_intersect_pressed);
    connect(occt_controls, &OcctQtControls::toolButton_spline_line_pressed, this, &MainWindow::on_toolButton_spline_line_pressed);
}

//! Destructor.
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionwireframe_triggered()
{
    occt_viewer->show_as_wireframe();
}

void MainWindow::on_actionshaded_triggered()
{
    occt_viewer->show_as_shaded();
}

void MainWindow::on_actionboundary_show_triggered()
{
    occt_viewer->show_boundary();
}

void MainWindow::on_actionboundary_hide_triggered()
{
    occt_viewer->hide_boundary();
}

void MainWindow::on_actionorthographic_triggered()
{
    occt_viewer->set_orthographic();
}

void MainWindow::on_actionperspective_triggered()
{
    occt_viewer->set_perspective();
}

void MainWindow::on_actioncube_hide_triggered()
{
    occt_viewer->hide_cube();
}

void MainWindow::on_actioncube_show_triggered()
{
    occt_viewer->show_cube();
}

void MainWindow::on_actiontriedron_hide_triggered()
{
    occt_viewer->hide_triedron();
}

void MainWindow::on_actiontriedron_show_triggered()
{
    occt_viewer->show_triedron();
}

void MainWindow::on_actiontranceparancy_dialog_triggered()
{
    transparancy->show();
}

void MainWindow::mainloop(){

    //! Opencascade callback thread.
    //! This thread can be used to process occt localtransformations etc.
    if(!occt_viewer->View().IsNull()){

        occt_controls->lbl_x->setText(QString::number(occt_viewer->aMousePnt.X(),'f',3));
        occt_controls->lbl_y->setText(QString::number(occt_viewer->aMousePnt.Y(),'f',3));
        occt_controls->lbl_z->setText(QString::number(occt_viewer->aMousePnt.X(),'f',3));

        if(occt_controls->btn_zoom_extends->isDown()==true){
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_plus->isDown()==true){
            occt_viewer->UpdateZoom(1);
            occt_viewer->update();
        }
        if(occt_controls->btn_zoom_min->isDown()==true){
            occt_viewer->UpdateZoom(-1);
            occt_viewer->update();
        }
        if(occt_controls->btn_zoom_front->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Yneg);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_back->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Ypos);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_left->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Xneg);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_right->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Xpos);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_top->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Zpos);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_bottom->isDown()==true){
            occt_viewer->View()->SetProj(V3d_Zneg);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(occt_controls->btn_zoom_3d->isDown()==true){
            occt_viewer->View()->SetProj(V3d_TypeOfOrientation_Zup_AxoRight);
            occt_viewer->View()->FitAll(0.01,Standard_True);
        }
        if(transparancy->isVisible()){
            occt_viewer->set_tranceparancy(0.01*transparancy->value);
            //! This is done here, otherwise it will not do a live update.
            occt_viewer->View()->Redraw();
            occt_viewer->update();
        }
        if(!oneshot){
            occt_viewer->View()->SetProj(V3d_TypeOfOrientation_Zup_AxoRight);
            double value=0.01*Tranceparancy().value;
            occt_viewer->set_tranceparancy(value);
            occt_viewer->View()->FitAll(0.01,Standard_True);
            occt_viewer->View()->Redraw();
            oneshot=1;
        }
    }
}

void MainWindow::on_toolButton_intersect_pressed()
{
    std::cout<<"btn pressed"<<std::endl;

    //! Draw a 3p 3d arc.
    gp_Pnt p0(0,0,0);
    gp_Pnt p1(100,100,0);
    gp_Pnt p2(200,0,0);
    occt_viewer->show_shape(ArcShape(p0,p1,p2).Shape());

    TopoDS_Shape aSphere = BRepPrimAPI_MakeSphere(ArcCenter(p0,p1,p2).Arc_cp(),ArcCenter(p0,p1,p2).Arc_radius()).Shape();
    Handle(AIS_Shape) myShape1=new AIS_Shape(aSphere);
    myShape1->SetTransparency(0.8);
    myShape1->SetDisplayMode(AIS_Shaded);
    occt_viewer->show_shape(myShape1);

    //! Draw a 2p 3d line.
    gp_Pnt p4(-250,0,0);
    gp_Pnt p5(250,75,10);
    occt_viewer->show_shape(LineShape(p4,p5).Shape());

    std::vector<gp_Pnt> pvec;
    bool ok=LineSphere(p4,p5,ArcCenter(p0,p1,p2).Arc_cp(),ArcCenter(p0,p1,p2).Arc_radius()).Intersect(pvec);


    if(ok){
        for(unsigned int i=0; i<pvec.size(); i++){
            std::cout<<"pvec at i"<<i<<" x:"<<pvec.at(i).X()<<" y:"<< pvec.at(i).Y()<<" z:"<< pvec.at(i).Z()<<std::endl;
            TopoDS_Shape aSphere = BRepPrimAPI_MakeSphere(pvec.at(i),5).Shape();
            Handle(AIS_Shape) myShape=new AIS_Shape(aSphere);
            myShape->SetDisplayMode(AIS_Shaded);

            //! Check if intersection is on the arc-plane.
            bool on_plane=PointPlane<double>(p0,p1,p2,pvec.at(i)).IsOnPlane();
            if(on_plane){
                myShape->SetColor(Quantity_NOC_BLUE);
            } else {
                myShape->SetColor(Quantity_NOC_RED);
            }
            occt_viewer->show_shape(myShape);

        }
    }
}

void MainWindow::on_toolButton_spline_line_pressed(){
    gp_Pnt p0={-100,0,0};
    gp_Pnt p1={250,0,0};
    occt_viewer->show_shape(LineShape({-100,0,0},{250,0,0}).Shape());

    gp_Pnt p2={-50,-100,0};
    gp_Pnt p3={-25,100,0};
    gp_Pnt p4={200,200,0};
    gp_Pnt p5={-60,-75,0};
    occt_viewer->show_shape(SplineShape({p2,p3,p4,p5}).Shape());

    std::vector<gp_Pnt> pvec;
    bool ok=SplineShape({p2,p3,p4,p5}).SplineLineIntersect(p0,p1,pvec);

    if(ok){
        for(unsigned int i=0; i<pvec.size(); i++){
            std::cout<<"pvec at i"<<i<<" x:"<<pvec.at(i).X()<<" y:"<< pvec.at(i).Y()<<" z:"<< pvec.at(i).Z()<<std::endl;
            TopoDS_Shape aSphere = BRepPrimAPI_MakeSphere(pvec.at(i),5).Shape();
            Handle(AIS_Shape) myShape=new AIS_Shape(aSphere);
            myShape->SetColor(Quantity_NOC_BLUE);
            myShape->SetDisplayMode(AIS_Shaded);
            occt_viewer->show_shape(myShape);
        }
    }
}















































