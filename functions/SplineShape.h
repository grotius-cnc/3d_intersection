#ifndef SPLINESHAPE_H
#define SPLINESHAPE_H

//! Opencascade.
#include <gp_Pnt.hxx>
#include <AIS_Shape.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>

//! Libspline.
#include <libspline/cubic_spline.h>
#include "LineLine.h"

class SplineShape
{
public:
    Handle(AIS_Shape) myShape;
    BRepBuilderAPI_MakeWire aWire;
    std::vector<gp_Pnt> pointvec;
    std::vector<gp_Pnt> splinepoints;

    //! Initialize spline, given the waypoints.
    SplineShape(std::vector<gp_Pnt> _pointvec) : pointvec(_pointvec) {
        std::vector<Vector3d> path; // libspline input
        for(unsigned int i=0; i<pointvec.size(); i++){
            path.push_back(Vector3d(pointvec.at(i).X(),pointvec.at(i).Y(),pointvec.at(i).Z()));
        }
        CubicSpline c_spline(path,20);
        c_spline.BuildSpline(path);
        std::vector<double> c_pathx(c_spline.GetPositionProfile().size());
        std::vector<double> c_pathy(c_spline.GetPositionProfile().size());
        std::vector<double> c_pathz(c_spline.GetPositionProfile().size());

        // Store wire points(p) into pointvector (pvec)
        gp_Pnt p;
        std::vector<gp_Pnt> pvec;
        // Get profile data for position, speed, acceleration, and curvature
        std::vector<double> ti(c_spline.GetPositionProfile().size());
        for(unsigned int i=0;i<c_pathx.size();++i)
        {
            c_pathx[i] = c_spline.GetPositionProfile()[i].x();
            c_pathy[i] = c_spline.GetPositionProfile()[i].y();
            c_pathz[i] = c_spline.GetPositionProfile()[i].z();

            p= {c_pathx[i],c_pathy[i],c_pathz[i]};
            pvec.push_back(p);
        }

        TopoDS_Edge edge;
        gp_Pnt p1=pvec[0], p2={0,0,0};
        splinepoints.push_back(p1);
        for(unsigned int i=1; i<pvec.size(); i++){
            //! A system to avoid duplicates.
            p2=pvec.at(i);
            if(p1.X()!=p2.X() || p1.Y()!=p2.Y() || p1.Z()!=p2.Z()){
                edge = BRepBuilderAPI_MakeEdge(p1,p2);
                aWire.Add(edge);
                p1=p2;
                splinepoints.push_back(p2);
            } else {
                std::cout<<"duplicate from spline function"<<std::endl;
            }
        }
    }

    //! Return the shape.
    Handle(AIS_Shape) Shape(){
        return new AIS_Shape(aWire);
    }

    //! Intersect spline with a line, given the line start + endpoint.
    bool SplineLineIntersect(gp_Pnt p0, gp_Pnt p1, std::vector<gp_Pnt> &pvec){
        gp_Pnt pa,pb;

        for(unsigned int i=0; i<splinepoints.size()-1; i++){
            bool ok=LineLine(p0,p1,splinepoints.at(i),splinepoints.at(i+1)).Intersect(pa,pb);
            //! if ok, pa=pb.
            if(ok){
                pvec.push_back(pa);
                std::cout<<"intersection found at x:"<<pa.X()<<" y:"<<pa.Y()<<" z:"<<pa.Z()<<std::endl;
            }
        }
        if(pvec.size()>0){
            return 1;
        }
        std::cout<<"empty splinepoints vector"<<std::endl;
        return 0;
    }
};

#endif // SPLINESHAPE_H













