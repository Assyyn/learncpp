#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include "Point3d.h"

#include <iostream>

class Vector3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);
    void print() const;

    friend void Point3d::moveByVector(
        const Vector3d&
            v); // Point3d::moveByVector() is now a friend of class Vector3d
};

#endif