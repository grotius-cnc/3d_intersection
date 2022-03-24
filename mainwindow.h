#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTimer>
#include <OcctQtViewer.h>
#include <OcctQtControls.h>
#include <Tranceparancy.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mainloop();

    OcctQtViewer *occt_viewer=new OcctQtViewer();
    OcctQtControls *occt_controls=new OcctQtControls();
    Tranceparancy *transparancy= new Tranceparancy();

private slots:

    void on_actionwireframe_triggered();

    void on_actionshaded_triggered();

    void on_actionboundary_show_triggered();

    void on_actionboundary_hide_triggered();


    void on_actionorthographic_triggered();

    void on_actionperspective_triggered();

    void on_actioncube_hide_triggered();

    void on_actioncube_show_triggered();

    void on_actiontranceparancy_dialog_triggered();

    void on_actiontriedron_hide_triggered();

    void on_actiontriedron_show_triggered();


    void on_toolButton_intersect_pressed();

    void on_toolButton_spline_line_pressed();

private:
    bool oneshot=0;
    QTimer *timer = new QTimer(this);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
