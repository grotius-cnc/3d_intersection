#ifndef LINESHAPE_H
#define LINESHAPE_H

//! Opencascade.
#include <gp_Pnt.hxx>
#include <AIS_Shape.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

//! Libspline.
#include <libspline/cubic_spline.h>

class LineShape
{
public:

    gp_Pnt p0,p1;
    //! Initialize.
    LineShape(gp_Pnt _p0, gp_Pnt _p1) : p0(_p0), p1(_p1) {

    }

    //! Return the shape.
    Handle(AIS_Shape) Shape(){
        TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge(p0,p1);
        Handle(AIS_Shape) myShape=new AIS_Shape(aEdge);
        return myShape;
    }
};


#endif // LINESHAPE_H
