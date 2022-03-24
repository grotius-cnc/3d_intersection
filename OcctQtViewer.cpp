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

//! Edited by Skynet Cyberdyne 01-2021.

#include <QApplication>
#include <QMessageBox>
#include <QMouseEvent>

#ifdef _WIN32
#include <windows.h>
#endif
#include <OpenGl_Context.hxx>

#include "OcctQtViewer.h"

#include <Standard_WarningsDisable.hxx>

#include <Standard_WarningsRestore.hxx>

#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Aspect_NeutralWindow.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <Message.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <OpenGl_FrameBuffer.hxx>

namespace
{
//! Map Qt buttons bitmask to virtual keys.
Aspect_VKeyMouse qtMouseButtons2VKeys (Qt::MouseButtons theButtons)
{
    Aspect_VKeyMouse aButtons = Aspect_VKeyMouse_NONE;
    if ((theButtons & Qt::LeftButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_LeftButton;
    }
    if ((theButtons & Qt::MiddleButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_MiddleButton;
    }
    if ((theButtons & Qt::RightButton) != 0)
    {
        aButtons |= Aspect_VKeyMouse_RightButton;
    }
    return aButtons;
}

//! Map Qt mouse modifiers bitmask to virtual keys.
Aspect_VKeyFlags qtMouseModifiers2VKeys (Qt::KeyboardModifiers theModifiers)
{
    Aspect_VKeyFlags aFlags = Aspect_VKeyFlags_NONE;
    if ((theModifiers & Qt::ShiftModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_SHIFT;
    }
    if ((theModifiers & Qt::ControlModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_CTRL;
    }
    if ((theModifiers & Qt::AltModifier) != 0)
    {
        aFlags |= Aspect_VKeyFlags_ALT;
    }
    return aFlags;
}

//! Map Qt key to virtual key.
Aspect_VKey qtKey2VKey (int theKey)
{
    switch (theKey)
    {
    case 1060: // ru
    case Qt::Key_A: return Aspect_VKey_A;
    case 1048: // ru
    case Qt::Key_B: return Aspect_VKey_B;
    case 1057: // ru
    case Qt::Key_C: return Aspect_VKey_C;
    case 1042: // ru
    case Qt::Key_D: return Aspect_VKey_D;
    case 1059: // ru
    case Qt::Key_E: return Aspect_VKey_E;
    case 1040: // ru
    case Qt::Key_F: return Aspect_VKey_F;
    case Qt::Key_G: return Aspect_VKey_G;
    case Qt::Key_H: return Aspect_VKey_H;
    case Qt::Key_I: return Aspect_VKey_I;
    case Qt::Key_J: return Aspect_VKey_J;
    case Qt::Key_K: return Aspect_VKey_K;
    case 1044: // ru
    case Qt::Key_L: return Aspect_VKey_L;
    case Qt::Key_M: return Aspect_VKey_M;
    case Qt::Key_N: return Aspect_VKey_N;
    case Qt::Key_O: return Aspect_VKey_O;
    case Qt::Key_P: return Aspect_VKey_P;
    case 1049: // ru
    case Qt::Key_Q: return Aspect_VKey_Q;
    case 1050: // ru
    case Qt::Key_R: return Aspect_VKey_R;
    case 1067: // ru
    case Qt::Key_S: return Aspect_VKey_S;
    case 1045: // ru
    case Qt::Key_T: return Aspect_VKey_T;
    case Qt::Key_U: return Aspect_VKey_U;
    case 1052: // ru
    case Qt::Key_V: return Aspect_VKey_V;
    case 1062: // ru
    case Qt::Key_W: return Aspect_VKey_W;
    case 1063: // ru
    case Qt::Key_X: return Aspect_VKey_X;
    case Qt::Key_Y: return Aspect_VKey_Y;
    case 1071: // ru
    case Qt::Key_Z: return Aspect_VKey_Z;
        //
    case Qt::Key_0: return Aspect_VKey_0;
    case Qt::Key_1: return Aspect_VKey_1;
    case Qt::Key_2: return Aspect_VKey_2;
    case Qt::Key_3: return Aspect_VKey_3;
    case Qt::Key_4: return Aspect_VKey_4;
    case Qt::Key_5: return Aspect_VKey_5;
    case Qt::Key_6: return Aspect_VKey_6;
    case Qt::Key_7: return Aspect_VKey_7;
    case Qt::Key_8: return Aspect_VKey_8;
    case Qt::Key_9: return Aspect_VKey_9;
        //
    case Qt::Key_F1:        return Aspect_VKey_F1;
    case Qt::Key_F2:        return Aspect_VKey_F2;
    case Qt::Key_F3:        return Aspect_VKey_F3;
    case Qt::Key_F4:        return Aspect_VKey_F4;
    case Qt::Key_F5:        return Aspect_VKey_F5;
    case Qt::Key_F6:        return Aspect_VKey_F6;
    case Qt::Key_F7:        return Aspect_VKey_F7;
    case Qt::Key_F8:        return Aspect_VKey_F8;
    case Qt::Key_F9:        return Aspect_VKey_F9;
    case Qt::Key_F10:       return Aspect_VKey_F10;
    case Qt::Key_F11:       return Aspect_VKey_F11;
    case Qt::Key_F12:       return Aspect_VKey_F12;
        //
    case Qt::Key_Up:        return Aspect_VKey_Up;
    case Qt::Key_Left:      return Aspect_VKey_Left;
    case Qt::Key_Right:     return Aspect_VKey_Right;
    case Qt::Key_Down:      return Aspect_VKey_Down;
    case Qt::Key_Plus:      return Aspect_VKey_Plus;
    case Qt::Key_Minus:     return Aspect_VKey_Minus;
    case Qt::Key_Equal:     return Aspect_VKey_Equal;
    case Qt::Key_PageDown:  return Aspect_VKey_PageDown;
    case Qt::Key_PageUp:    return Aspect_VKey_PageUp;
    case Qt::Key_Home:      return Aspect_VKey_Home;
    case Qt::Key_End:       return Aspect_VKey_End;
    case Qt::Key_Escape:    return Aspect_VKey_Escape;
    case Qt::Key_Back:      return Aspect_VKey_Back;
    case Qt::Key_Enter:     return Aspect_VKey_Enter;
    case Qt::Key_Backspace: return Aspect_VKey_Backspace;
    case Qt::Key_Space:     return Aspect_VKey_Space;
    case Qt::Key_Delete:    return Aspect_VKey_Delete;
    case Qt::Key_Tab:       return Aspect_VKey_Tab;
    case 1025:
    case Qt::Key_QuoteLeft: return Aspect_VKey_Tilde;
        //
    case Qt::Key_Shift:     return Aspect_VKey_Shift;
    case Qt::Key_Control:   return Aspect_VKey_Control;
    case Qt::Key_Alt:       return Aspect_VKey_Alt;
    case Qt::Key_Menu:      return Aspect_VKey_Menu;
    case Qt::Key_Meta:      return Aspect_VKey_Meta;
    default:                return Aspect_VKey_UNKNOWN;
    }
}
}

//! OcctQtViewer
OcctQtViewer::OcctQtViewer (QWidget* theParent)
    : QOpenGLWidget (theParent),
      myIsCoreProfile (true)
{
    Handle(Aspect_DisplayConnection) aDisp = new Aspect_DisplayConnection();
    Handle(OpenGl_GraphicDriver) aDriver = new OpenGl_GraphicDriver (aDisp, false);
    aDriver->ChangeOptions().ffpEnable = Standard_False;
    //! aDriver->ChangeOptions().glslWarnings = Standard_True;
    aDriver->ChangeOptions().buffersNoSwap = Standard_False;

    //! lets QOpenGLWidget to manage buffer swap
    aDriver->ChangeOptions().buffersNoSwap = true;
    //! don't write into alpha channel
    //! aDriver->ChangeOptions().buffersOpaqueAlpha = true;
    //! offscreen FBOs should be always used
    aDriver->ChangeOptions().useSystemBuffer = false;

    //! create viewer
    myViewer = new V3d_Viewer (aDriver);
    myViewer->SetDefaultBackgroundColor (Quantity_NOC_GRAY);
    myViewer->SetDefaultLights();
    myViewer->SetLightOn();
    //! myViewer->ActivateGrid (Aspect_GT_Rectangular, Aspect_GDM_Lines);

    //! create AIS context
    myContext = new AIS_InteractiveContext (myViewer);

    //! 3D navigation cube.
    myViewCube = new AIS_ViewCube();
    myViewCube->SetViewAnimation (myViewAnimation);
    myViewCube->SetBoxColor(Quantity_NOC_GRAY75); //
    myViewCube->SetDrawAxes(false); //
    myViewCube->SetFixedAnimationLoop (false);
    myViewCube->SetAutoStartAnimation (true);
    myViewCube->SetSize(40);
    myViewCube->SetFontHeight(10);
    myViewCube->SetTransformPersistence(
                new Graphic3d_TransformPers(
                    Graphic3d_TMF_TriedronPers,
                    Aspect_TOTP_LEFT_LOWER,
                    Graphic3d_Vec2i(85, 85)));

    //! note - window will be created later within initializeGL() callback!
    myView = myViewer->CreateView();
    myView->SetImmediateUpdate (false);

    //! Print the actual opencascade performance.
    bool show_specs=1;
    if(show_specs){
        myView->ChangeRenderingParams().NbMsaaSamples = 4; // warning - affects performance
        myView->ChangeRenderingParams().ToShowStats = true;
        myView->ChangeRenderingParams().CollectedStats = (Graphic3d_RenderingParams::PerfCounters )
                (Graphic3d_RenderingParams::PerfCounters_FrameRate
                 | Graphic3d_RenderingParams::PerfCounters_Triangles);
    }

    //! Set model view as perspective.
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Perspective);

    /// Show triedron. This is the 3d axis cross at the lower left of the screen.
    myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

    //! Qt widget setup
    setMouseTracking (true);
    setBackgroundRole (QPalette::NoRole);   //! or NoBackground
    setFocusPolicy (Qt::StrongFocus);       //! set focus policy to threat QContextMenuEvent from keyboard
    setUpdatesEnabled (true);
    setUpdateBehavior (QOpenGLWidget::NoPartialUpdate);

    //! OpenGL setup managed by Qt
    QSurfaceFormat aGlFormat;
    aGlFormat.setDepthBufferSize   (24);
    aGlFormat.setStencilBufferSize (8);
    //! aGlFormat.setOption (QSurfaceFormat::DebugContext, true);
    //! aGlFormat.setOption (QSurfaceFormat::DeprecatedFunctions, true);
    if (myIsCoreProfile)
    {
        aGlFormat.setVersion (4, 5);
    }
    aGlFormat.setProfile (myIsCoreProfile ? QSurfaceFormat::CoreProfile : QSurfaceFormat::CompatibilityProfile);
#if (QT_VERSION_MAJOR > 5) || (QT_VERSION_MAJOR == 5 && QT_VERSION_MINOR >= 10)
    aGlFormat.setColorSpace (QSurfaceFormat::sRGBColorSpace);
    setTextureFormat (GL_SRGB8_ALPHA8);
#else
    Message::SendWarning ("Warning! Qt 5.10+ is required for sRGB setup.\n"
                          "Colors in 3D Viewer might look incorrect (Qt " QT_VERSION_STR " is used).\n");
    aDriver->ChangeOptions().sRGBDisable = true;
#endif
    setFormat (aGlFormat);

#if defined(_WIN32)
    // never use ANGLE on Windows, since OCCT 3D Viewer does not expect this
    QCoreApplication::setAttribute (Qt::AA_UseDesktopOpenGL);
    //QCoreApplication::setAttribute (Qt::AA_UseOpenGLES);
#endif

}

//! Destructor ~OcctQtViewer
OcctQtViewer::~OcctQtViewer()
{
    // hold on X11 display connection till making another connection active by glXMakeCurrent()
    // to workaround sudden crash in QOpenGLWidget destructor
    Handle(Aspect_DisplayConnection) aDisp = myViewer->Driver()->GetDisplayConnection();

    // release OCCT viewer
    myContext->RemoveAll (false);
    myContext.Nullify();
    myView->Remove();
    myView.Nullify();
    myViewer.Nullify();

    //! make active OpenGL context created by Qt
    makeCurrent();
    aDisp.Nullify();
}

//! dumpGlInfo
void OcctQtViewer::dumpGlInfo (bool theIsBasic)
{
    TColStd_IndexedDataMapOfStringString aGlCapsDict;
    myView->DiagnosticInformation (aGlCapsDict, theIsBasic ? Graphic3d_DiagnosticInfo_Basic : Graphic3d_DiagnosticInfo_Complete);
    TCollection_AsciiString anInfo;
    for (TColStd_IndexedDataMapOfStringString::Iterator aValueIter (aGlCapsDict); aValueIter.More(); aValueIter.Next())
    {
        if (!aValueIter.Value().IsEmpty())
        {
            if (!anInfo.IsEmpty())
            {
                anInfo += "\n";
            }
            anInfo += aValueIter.Key() + ": " + aValueIter.Value();
        }
    }

    Message::SendInfo (anInfo);
    myGlInfo = QString::fromUtf8 (anInfo.ToCString());
}

//! initializeGL
#include <OpenGl_VertexBuffer.hxx>

void OcctQtViewer::initializeGL()
{
    const QRect aRect = rect();
    const Graphic3d_Vec2i aViewSize (aRect.right() - aRect.left(), aRect.bottom() - aRect.top());

    Handle(OpenGl_Context) aGlCtx = new OpenGl_Context();
    if (!aGlCtx->Init (myIsCoreProfile))
    {
        Message::SendFail() << "Error: OpenGl_Context is unable to wrap OpenGL context";
        QMessageBox::critical (0, "Failure", "OpenGl_Context is unable to wrap OpenGL context");
        QApplication::exit (1);
        return;
    }

    Handle(Aspect_NeutralWindow) aWindow = Handle(Aspect_NeutralWindow)::DownCast (myView->Window());
    if (!aWindow.IsNull())
    {
        aWindow->SetSize (aViewSize.x(), aViewSize.y());
        myView->SetWindow (aWindow, (Aspect_RenderingContext) glXGetCurrentContext());

        dumpGlInfo (true);
    }
    else
    {
        aWindow = new Aspect_NeutralWindow();

        Aspect_Drawable aNativeWin = (Aspect_Drawable )winId();
#ifdef _WIN32
        //HGLRC aWglCtx    = wglGetCurrentContext();
        HDC   aWglDevCtx = wglGetCurrentDC();
        HWND  aWglWin    = WindowFromDC (aWglDevCtx);
        aNativeWin = (Aspect_Drawable )aWglWin;
#endif
        aWindow->SetNativeHandle (aNativeWin);
        aWindow->SetSize (aViewSize.x(), aViewSize.y());
        myView->SetWindow (aWindow, (Aspect_RenderingContext) glXGetCurrentContext());
        dumpGlInfo (true);

        myContext->Display (myViewCube, 0, 0, false);
    }

    //! dummy shape for testing
    /*
    TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox (100.0, 50.0, 90.0).Shape();
    aShapeVec.push_back(new AIS_Shape (aTopoBox));
    //! Set shape boundary line enable.
    aShapeVec.back()->Attributes()->SetFaceBoundaryDraw(true);
    aShapeVec.back()->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
    aShapeVec.back()->Attributes()->SetIsoOnTriangulation(true);
    aShapeVec.back()->Attributes()->SetDisplayMode(AIS_Shaded);
    myContext->Display (aShapeVec.back(),Standard_False);
    */
}

//! closeEvent
void OcctQtViewer::closeEvent (QCloseEvent* theEvent)
{
    theEvent->accept();
}

//! keyPressEvent
void OcctQtViewer::keyPressEvent (QKeyEvent* theEvent)
{
    Aspect_VKey aKey = qtKey2VKey (theEvent->key());
    switch (aKey)
    {
    case Aspect_VKey_Escape:
    {
        QApplication::exit();
        return;
    }
    case Aspect_VKey_F:
    {
        myView->FitAll (0.01, false);
        update();
        return;
    }
    }
    QOpenGLWidget::keyPressEvent (theEvent);
}


//! mousePressEvent
void OcctQtViewer::mousePressEvent (QMouseEvent* theEvent)
{
    QOpenGLWidget::mousePressEvent (theEvent);
    const Graphic3d_Vec2i aPnt (theEvent->pos().x(), theEvent->pos().y());
    const Aspect_VKeyFlags aFlags = qtMouseModifiers2VKeys (theEvent->modifiers());
    if (!myView.IsNull()
            && UpdateMouseButtons (aPnt,
                                   qtMouseButtons2VKeys (theEvent->buttons()),
                                   aFlags,
                                   false))
    {
        updateView();
    }
}

//! mouseReleaseEvent
void OcctQtViewer::mouseReleaseEvent (QMouseEvent* theEvent)
{
    QOpenGLWidget::mouseReleaseEvent (theEvent);
    const Graphic3d_Vec2i aPnt (theEvent->pos().x(), theEvent->pos().y());
    const Aspect_VKeyFlags aFlags = qtMouseModifiers2VKeys (theEvent->modifiers());
    if (!myView.IsNull()
            && UpdateMouseButtons (aPnt,
                                   qtMouseButtons2VKeys (theEvent->buttons()),
                                   aFlags,
                                   false))
    {
        updateView();
    }
}

//! mouseMoveEvent
void OcctQtViewer::mouseMoveEvent (QMouseEvent* theEvent)
{
    for(myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected()){
        if(myContext->MainSelector()->NbPicked()>0){
            aMousePnt=myContext->MainSelector()->PickedPoint(1).XYZ();
        }
    }

    QOpenGLWidget::mouseMoveEvent (theEvent);
    const Graphic3d_Vec2i aNewPos (theEvent->pos().x(), theEvent->pos().y());
    if (!myView.IsNull()
            && UpdateMousePosition (aNewPos,
                                    qtMouseButtons2VKeys (theEvent->buttons()),
                                    qtMouseModifiers2VKeys (theEvent->modifiers()),
                                    false))
    {
        updateView();
    }
}

//! wheelEvent
void OcctQtViewer::wheelEvent (QWheelEvent* theEvent)
{
    QOpenGLWidget::wheelEvent (theEvent);
    const Graphic3d_Vec2i aPos (theEvent->position().x(), theEvent->position().y());
    if (!myView.IsNull()
            && UpdateZoom (Aspect_ScrollDelta (aPos, theEvent->delta() / 8)))
    {
        updateView();
    }
}

//! updateView
void OcctQtViewer::updateView()
{
    update();
    //! if (window() != NULL) { window()->update(); }
}

//! paintGL
void OcctQtViewer::paintGL()
{
    if (myView->Window().IsNull())
    {
        return;
    }

    //! wrap FBO created by QOpenGLWidget
    Handle(OpenGl_GraphicDriver) aDriver = Handle(OpenGl_GraphicDriver)::DownCast (myContext->CurrentViewer()->Driver());
    const Handle(OpenGl_Context)& aGlCtx = aDriver->GetSharedContext();
    Handle(OpenGl_FrameBuffer) aDefaultFbo = aGlCtx->DefaultFrameBuffer();
    if (aDefaultFbo.IsNull())
    {
        aDefaultFbo = new OpenGl_FrameBuffer();
        aGlCtx->SetDefaultFrameBuffer (aDefaultFbo);
    }
    if (!aDefaultFbo->InitWrapper (aGlCtx))
    {
        aDefaultFbo.Nullify();
        Message::DefaultMessenger()->Send ("Default FBO wrapper creation failed", Message_Fail);
        QMessageBox::critical (0, "Failure", "Default FBO wrapper creation failed");
        QApplication::exit (1);
        return;
    }

    Graphic3d_Vec2i aViewSizeOld;
    //! const QRect aRect = rect(); Graphic3d_Vec2i aViewSizeNew(aRect.right() - aRect.left(), aRect.bottom() - aRect.top());
    Graphic3d_Vec2i aViewSizeNew(aDefaultFbo->GetVPSizeX(),aDefaultFbo->GetVPSizeY());
    Handle(Aspect_NeutralWindow) aWindow = Handle(Aspect_NeutralWindow)::DownCast (myView->Window());
    aWindow->Size (aViewSizeOld.x(), aViewSizeOld.y());
    if (aViewSizeNew != aViewSizeOld)
    {
        aWindow->SetSize (aViewSizeNew.x(), aViewSizeNew.y());
        myView->MustBeResized();
        myView->Invalidate();
    }

    //! flush pending input events and redraw the viewer
    myView->InvalidateImmediate();
    FlushViewEvents (myContext, myView, true);
}

//! handleViewRedraw
void OcctQtViewer::handleViewRedraw (const Handle(AIS_InteractiveContext)& theCtx,
                                     const Handle(V3d_View)& theView)
{
    AIS_ViewController::handleViewRedraw (theCtx, theView);
    if (myToAskNextFrame)
    {
        //! ask more frames for animation
        updateView();
    }
}

//! Set the tranceparancy between 0 & 1.
void OcctQtViewer::set_tranceparancy(double value){
    for(unsigned int i=0; i<aShapeVec.size(); i++){
        aShapeVec.at(i)->SetTransparency(value);
    }
}

//! Set background color.
void OcctQtViewer::set_backgroundcolor(double r, double g, double b){
    Quantity_Color cola,colb;
    cola.SetValues(r/255,g/255,b/255,Quantity_TOC_RGB);
    colb.SetValues(r/255,g/255,b/255,Quantity_TOC_RGB);
    myView->SetBgGradientColors(cola,colb,Aspect_GFM_DIAG2 , false);
}

//! Show the boundary line of the shapes.
void OcctQtViewer::show_boundary(){
    for(unsigned int i=0; i<aShapeVec.size(); i++){
        aShapeVec[i]->Attributes()->SetFaceBoundaryDraw(true);
        aShapeVec[i]->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        aShapeVec[i]->Attributes()->SetIsoOnTriangulation(true);
        myContext->Redisplay(aShapeVec[i],Standard_False);
    }
    myView->Update();
}

//! Hide the boundary lines of the shapes.
void OcctQtViewer::hide_boundary(){
    for(unsigned int i=0; i<aShapeVec.size(); i++){
        aShapeVec[i]->Attributes()->SetFaceBoundaryDraw(false);
        //! aShapeVec[i]->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.));
        aShapeVec[i]->Attributes()->SetIsoOnTriangulation(false);
        myContext->Redisplay(aShapeVec[i],Standard_False);
    }
    myView->Update();
}

//! Hide the navigation cube.
void OcctQtViewer::hide_cube(){
    myContext->Erase(myViewCube, false);
    myView->Update();
}

//! Hide the navigation cube.
void OcctQtViewer::show_cube(){
    myContext->Display(myViewCube, false);
    myView->Update();
}

//! Show the trihedron
void OcctQtViewer::show_triedron(){
    myView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
    myView->Update();
}

//! Hide the trihedron
void OcctQtViewer::hide_triedron(){
    myView->TriedronErase();
    myView->Update();
}

//! Show as wireframe
void OcctQtViewer::show_as_wireframe(){
    for(unsigned int i=0; i<aShapeVec.size(); i++){
        aShapeVec[i]->SetDisplayMode(AIS_WireFrame);
        myContext->Remove(aShapeVec[i],Standard_False);
        myContext->Display(aShapeVec[i],Standard_False);
    }
    myView->Redraw();
    myView->Update();
}

//! Show as shaded
void OcctQtViewer::show_as_shaded(){
    for(unsigned int i=0; i<aShapeVec.size(); i++){
        aShapeVec[i]->SetDisplayMode(AIS_Shaded);
        myContext->Remove(aShapeVec[i],Standard_False);
        myContext->Display(aShapeVec[i],Standard_True);
    }
    myView->Redraw();
    myView->Update();
}

//! Display mode orthographic.
void OcctQtViewer::set_orthographic(){
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Orthographic);
    myView->Redraw();
    myView->Update();
}

//! Display mode perspective.
void OcctQtViewer::set_perspective(){
    myView->Camera()->SetProjectionType (Graphic3d_Camera::Projection_Perspective);
    myView->Redraw();
    myView->Update();
}

//! Show shape.
void OcctQtViewer::show_shape(Handle(AIS_Shape) shape){
    myContext->Display(shape,Standard_False);
    myView->Redraw();
}

//! Remove selected shape, release memory.
void OcctQtViewer::remove_shape(Handle(AIS_Shape) shape){

    //! Perfect way to avoid memory leaks.
    //! https://dev.opencascade.org/content/removing-interactive-objects-interactive-context
    myContext->SetSelected(shape,Standard_False);
    myContext->EraseSelected(Standard_False);
    //! sometimes the memory used for presentations and selections is not released.
    //! For this problem you should write one more code as below.
    myContext->Remove(shape, Standard_False);
    //! memory can be released by calling the Nullify() method of the Handle(AIS_Shape) object.
    shape.Nullify();
}










