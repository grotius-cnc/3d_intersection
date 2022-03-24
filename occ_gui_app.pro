QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET=occ_gui_app_mainwindow

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    OcctQtControls.cpp \
    OcctQtViewer.cpp \
    Tranceparancy.cpp \
    libspline/bezier_spline.cpp \
    libspline/cubic_spline.cpp \
    libspline/spline.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    OcctQtControls.h \
    OcctQtViewer.h \
    Tranceparancy.h \
    functions/ArcCenter.h \
    functions/ArcShape.h \
    functions/LineLine.h \
    functions/LineShape.h \
    functions/LineSphere.h \
    functions/PointPlane.h \
    functions/SplineShape.h \
    functions/Vector3D.h \
    libspline/bezier_spline.h \
    libspline/cubic_spline.h \
    libspline/spline.h \
    mainwindow.h

FORMS += \
    OcctQtControls.ui \
    Tranceparancy.ui \
    mainwindow.ui

# Occt widget
LIBS += -L/home/user/OcctQtWidget/build-OcctQtLib-Desktop-Debug -lOcctQtLib

# Opencascade
INCLUDEPATH += /opt/opencascade/oce-upstream-V7_5_0beta/inc \
               /opt/opencascade/oce-upstream-V7_5_0beta/src
LIBS+= -L/opt/opencascade/oce-upstream-V7_5_0beta/lin/gcc/lib \
       -L/opt/opencascade/oce-upstream-V7_5_0beta/lin/gcc/libd

LIBS += -lTKGeomAlgo -lTKMesh -lTKHLR -lTKBO -lTKShHealing
LIBS += -lTKPrim
LIBS += -lTKernel -lTKMath -lTKTopAlgo -lTKService
LIBS += -lTKG2d -lTKG3d -lTKV3d -lTKOpenGl
LIBS += -lTKBRep -lTKXSBase -lTKGeomBase
LIBS += -lTKXSDRAW
LIBS += -lTKLCAF -lTKXCAF -lTKCAF -lTKVCAF
LIBS += -lTKCDF -lTKBin -lTKBinL -lTKBinXCAF -lTKXml -lTKXmlL -lTKXmlXCAF
# -- IGES support
LIBS += -lTKIGES
# -- STEP support
LIBS += -lTKSTEP -lTKXDESTEP -lTKXDEIGES -lTKSTEPAttr -lTKSTEPBase -lTKSTEP209
# -- STL support
LIBS += -lTKSTL
# -- OBJ/glTF support
LIBS += -lTKRWMesh -lTKMeshVS
# -- VRML support
LIBS += -lTKVRML
# -- ViewerTest
LIBS += -lTKViewerTest
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    libicon/icons.qrc

DISTFILES += \
    readme.md
