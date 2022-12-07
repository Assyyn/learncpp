#include <iostream>

void case1() { // pointers can be made to point to another address
  int x{5};
  int *ptr{&x}; // ptr initialized to point at x

  std::cout
      << *ptr
      << '\n'; // print the value at the address being pointed to (x's address)

  int y{6};
  ptr = &y; // change ptr to point at y

  std::cout
      << *ptr
      << '\n'; // print the value at the address being pointed to (y's address)
}

void case2() { // pointers can be used to change the value being pointed at
  int x{5};
  int *ptr{&x}; // initialize ptr with address of variable x

  std::cout << x << '\n';    // print x's value
  std::cout << *ptr << '\n'; // print the value at the address that ptr is
                             // holding (x's address)

  *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note
            // that ptr is dereferenced here)

  std::cout << x << '\n';
  std::cout << *ptr << '\n'; // print the value at the address that ptr is
                             // holding (x's address)
}

int main() {
  case1();

  case2();

  return 0;
}
