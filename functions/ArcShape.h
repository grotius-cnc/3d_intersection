#ifndef ARCSHAPE_H
#define ARCSHAPE_H

//! Opencascade.
#include <gp_Pnt.hxx>
#include <AIS_Shape.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <TopoDS_Edge.hxx>

class ArcShape
{
public:

    gp_Pnt p0,p1,p2;
    //! Initialize.
    ArcShape(gp_Pnt _p0, gp_Pnt _p1, gp_Pnt _p2) : p0(_p0), p1(_p1), p2(_p2)  {

    }

    //! Return the shape.
    Handle(AIS_Shape) Shape(){
        Handle(Geom_TrimmedCurve) aArcOfCircle = GC_MakeArcOfCircle(p0,p1,p2);
        TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge(aArcOfCircle);
        Handle(AIS_Shape) myShape=new AIS_Shape(aEdge);
        return myShape;
    }



};

#endif // ARCSHAPE_H
