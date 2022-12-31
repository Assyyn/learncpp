# Question 1 description

- Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function. The following code should work:

```cpp
#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    return 0;
}
```

---

- Now add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as std::sqrt((x1 - x2) *(x1 - x2) + (y1 - y2)* (y1 - y2)). The std::sqrt function lives in header cmath. The following code should run:

```cpp
#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
```

---

- Change function distanceTo from a member function to a non-member friend function that takes two Points as parameters. Also rename it “distanceFrom”. The following code should run:

```cpp
#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}
```
