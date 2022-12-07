#include <iostream>

int main() {
  int x{5};
  int &ref{x};  // get a reference to x
  int *ptr{&x}; // get a pointer to x

  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (5)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

  ref = 6; // use the reference to change the value of x
  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (6)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

  *ptr = 7; // use the pointer to change the value of x
  std::cout << x;
  std::cout << ref;          // use the reference to print x's value (7)
  std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

  return 0;
}

// Differences:
//
// The primary difference is that with pointers, we need to explicitly get the
// address to point at, and we have to explicitly dereference the pointer to get
// the value. With references, the address-of and dereference happens
// implicitly.

// References must be initialized, pointers are not required to be initialized
// (but should be).
//
// References are not objects, pointers are.
//
// References can not be reseated (changed to reference something else),
// pointers can change what they are pointing at.
//
// References must always be bound to an object, pointers can point to nothing
// (we’ll see an example of this in the next lesson).
//
// References are “safe” (outside of dangling references), pointers are
// inherently dangerous (we’ll also discuss this in the next lesson).
