#ifndef POINT_3D_H
#define POINT_3D_H

#include <iostream>

class Vector3d;

class Point3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0);

    void print() const;

    void moveByVector(const Vector3d& v);
};

#endif