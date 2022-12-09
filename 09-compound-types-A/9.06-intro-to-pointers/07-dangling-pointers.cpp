// A dangling pointer is a pointer that is holding the address of an object that
// is no longer valid (e.g. because it has been destroyed). Dereferencing a
// dangling pointer will lead to undefined results.

#include <iostream>

int main() {
  int x{5};
  int *ptr(&x);

  std::cout << *ptr << '\n'; // valid, prints 5

  {
    int y{6};
    ptr = &y;

    std::cout << *ptr << '\n'; // valid
  }                            // y goes out of scope, and ptr is now dangling

  std::cout << *ptr
            << '\n'; // undefined behavior from Dereferencing a dangling pointer

  return 0;
}
