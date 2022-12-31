# Quiz time

1. In geometry, a point is a position in space. We can define a point in 3d-space as the set of coordinates x, y, and z. For example, the Point(2.0, 1.0, 0.0) would be the point at coordinate space x=2.0, y=1.0, and z=0.0.

In physics, a vector is a quantity that has a magnitude (length) and a direction (but no position). We can define a vector in 3d-space as an x, y, and z value representing the direction of the vector along the x, y, and z axis (the length can be derived from these). For example, the Vector(2.0, 0.0, 0.0) would be a vector representing a direction along the positive x-axis (only), with length 2.0.

A Vector can be applied to a Point to move the Point to a new position. This is done by adding the vector’s direction to the point’s position to yield a new position. For example, Point(2.0, 1.0, 0.0) + Vector(2.0, 0.0, 0.0) would yield the point (4.0, 1.0, 0.0).

Points and Vectors are often used in computer graphics (the point to represent vertices of shape, and vectors represent movement of the shape).

Given the [program](givenProgram.cpp),

1. Add a function to the Point class that takes a Vector as a parameter and adds the vector to the point. The function should return a new Point that is the result of the vector addition.

- a) Make Point3d a friend class of Vector3d, and implement function Point3d::moveByVector() done [here](solution1.cpp).
- b) Instead of making class Point3d a friend of class Vector3d, make member function Point3d::moveByVector a friend of class Vector3d. done [here](solution2.cpp).
- c) Reimplement the solution to quiz question 1b using 5 separate files: Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp. done [here](solution3/).

---

## Status :heavy_check_mark: , 3 solutions

### thanks to learncpp for the amazing quiz as always :heart: [learncpp.com](https://www.learncpp.com/)

### Goto :arrow_up_small: [top](#quiz-time)
