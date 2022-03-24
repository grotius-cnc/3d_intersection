// Copyright (c) 2021 OPEN CASCADE SAS
//
// This file is part of the examples of the Open CASCADE Technology software library.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE

//! Edited by Skynet Cyberdyne 01-2022.

#ifndef _OcctQtViewer_HeaderFile
#define _OcctQtViewer_HeaderFile

#include <Standard_WarningsDisable.hxx>
#include <QOpenGLWidget>
#include <Standard_WarningsRestore.hxx>

#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>
#include <V3d_View.hxx>
#include <AIS_ViewCube.hxx>
#include <AIS_Shape.hxx>

//! OCCT 3D View.
class OcctQtViewer : public QOpenGLWidget, public AIS_ViewController
{
  Q_OBJECT
public:

  //! Main constructor.
  OcctQtViewer (QWidget* theParent = nullptr);

  //! Destructor.
  virtual ~OcctQtViewer();

  //! Return Viewer.
  const Handle(V3d_Viewer)& Viewer() const { return myViewer; }

  //! Return View.
  const Handle(V3d_View)& View() const { return myView; }

  //! Return AIS context.
  const Handle(AIS_InteractiveContext)& Context() const { return myContext; }

  //! Return OpenGL info.
  const QString& getGlInfo() const { return myGlInfo; }

  //! Minial widget size.
  virtual QSize minimumSizeHint() const override { return QSize(200, 200); }

  //! Default widget size.
  virtual QSize sizeHint()        const override { return QSize(720, 480); }

  //! Set the tranceparancy level of the shapevec.
  void set_tranceparancy(double value);

  //! Set the background color. Red,green,blue. 0-255.
  void set_backgroundcolor(double r, double g, double b);

  //! Enable the shape contours lines to be viewed.
  void show_boundary();
  void hide_boundary();

  //! Show or hide the navigation cube.
  void show_cube();
  void hide_cube();

  //! Shape preview mode.
  void show_as_wireframe();
  void show_as_shaded();

  //! Triedron axis origin.
  void show_triedron();
  void hide_triedron();

  //! Display mode.
  void set_orthographic();
  void set_perspective();

  //! Shape.
  void show_shape(Handle(AIS_Shape) shape);
  void remove_shape(Handle(AIS_Shape) shape);

  //! Actual xyz mouse coordinates retrieved by hovering a active shape.
  gp_Pnt aMousePnt;

  //! A bucket containing all shapes.
  std::vector<Handle(AIS_InteractiveObject)> aShapeVec;

protected: // OpenGL events

  virtual void initializeGL() override;
  virtual void paintGL() override;
  //virtual void resizeGL(int , int ) override;

protected: // user input events

  virtual void closeEvent       (QCloseEvent*  theEvent) override;
  virtual void keyPressEvent    (QKeyEvent*    theEvent) override;
  virtual void mousePressEvent  (QMouseEvent*  theEvent) override;
  virtual void mouseReleaseEvent(QMouseEvent*  theEvent) override;
  virtual void mouseMoveEvent   (QMouseEvent*  theEvent) override;
  virtual void wheelEvent       (QWheelEvent*  theEvent) override;

private:

  //! Dump OpenGL info.
  void dumpGlInfo (bool theIsBasic);

  //! Request widget paintGL() event.
  void updateView();

  //! Handle view redraw.
  virtual void handleViewRedraw (const Handle(AIS_InteractiveContext)& theCtx,
                                 const Handle(V3d_View)& theView) override;
private:
  Handle(V3d_Viewer)             myViewer;
  Handle(V3d_View)               myView;
  Handle(AIS_InteractiveContext) myContext;
  Handle(AIS_ViewCube)           myViewCube;

  GLint m_vaoHandle;
  QString myGlInfo;
  bool myIsCoreProfile;
};

#endif // _OcctQtViewer_HeaderFile
