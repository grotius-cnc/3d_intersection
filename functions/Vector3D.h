#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>

/**
 * @brief Basic 3D vector class
 */
class Vector3D
{
public:
    double x,y,z;

    Vector3D(double _x=0, double _y=0, double _z=0)
        : x(_x), y(_y), z(_z)
    {
    }

    double dot(Vector3D v2)
    {
        return x*v2.x + y*v2.y + z*v2.z;
    }

    Vector3D operator+(const Vector3D& v2)
    {
        return Vector3D(x+v2.x, y+v2.y, z+v2.z);
    }

    Vector3D operator-(const Vector3D& v2)
    {
        return Vector3D(x-v2.x, y-v2.y, z-v2.z);
    }

    Vector3D operator*(const double& sc)
    {
        return Vector3D(sc*x, sc*y, sc*z);
    }

    double norm()
    {
        return sqrt(dot(*this));
    }
    //! Magnitude.
    double magnitude()
    {
        return sqrt(x*x + y*y + z*z);
    }

    //! Cross product.
    Vector3D crossproduct(Vector3D &v2){
        return Vector3D((y*v2.z)-(z*v2.y), (z*v2.x)-(x*v2.z), (x*v2.y)-(y*v2.x));
    }

    ////! http://www.fundza.com/vectors/normalize/
    Vector3D normalize(){

        /*
        The magnitude (length) of the vector is,

        length = sqrt((ax * ax) + (ay * ay) + (az * az))
        length = sqrt(9 + 1 + 4) = 3.742

        As a short-hand notation the magnitude of a vector is written with two vertical lines,

        |a| = sqrt((ax * ax) + (ay * ay) + (az * az))

        Unit Vectors - Normalizing

        Operations in 2D and 3D computer graphics are often performed using copies of vectors that have been normalized ie. converted to unit vectors. For example, the tutorial "RSL: Edge Effects" applies normalization before calculating the dot product of two vectors. Normalizing a vector involves two steps:
        1   calculate its length, then,
        2   divide each of its (xy or xyz) components by its length.

        Given vector a its xyz components are calculated as follows,

        x = ax/|a|
        y = ay/|a|
        z = az/|a|

        As a "worked example" the vector shown in figure 1 has the xyz components of 3, 1, 2 and a length of 3.742. Therefore, a normalized copy of the vector will have components,

        x = 3.0 / 3.742 = 0.802
        y = 1.0 / 3.742 = 0.267
        z = 2.0 / 3.742 = 0.534
        */

        double l=sqrt((x*x)+(y*y)+(z*z));
        return Vector3D(x/l,y/l,z/l);
    }
};

#endif // VECTOR3D_H
