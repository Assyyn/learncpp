#include <iostream>

int &max(int &x, int &y) { return (x > y) ? x : y; }

int main() {
  int a{20};
  int b{32};

  max(a, b) = 10; // sets the greater to 100

  std::cout << a << b << '\n'; // prints 2010

  max(a, b) = 30;

  std::cout << a << b << '\n'; // prints 3010

  return 0;
}
