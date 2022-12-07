#include <iostream>

int main() {
  // the address-of operator '&'
  int x{5};
  std::cout << x << '\n';  // print the value of variable x
  std::cout << &x << '\n'; // print the memory address of variable x

  // the dereference operator '*'
  std::cout << *(&x)
            << '\n'; // print the value at the memory address of variable x
                     // (parentheses not required, but make it easier to read)

  // declaring pointers
  int *ptr; // this is bad practice, why?
            // unitialized pointers hold garbage addresses

  // always initialize your pointers
  int *ptr2{};   // a null pointer
  int *ptr3{&x}; // a pointer initialized with the address of variable x

  // we can dereference a pointer
  std::cout << *ptr
            << '\n'; // use dereference operator to print the value at the
                     // address that ptr is holding (which is x's address)

  return 0;
}
