#include <iostream>

int main() {
  int *ptr{}; // a null pointer

  std::cout << *ptr << '\n'; // dereferencing a null pointer:
                             // BUT it doesn't have an address

  return 0;
}

// the program will cause undefined behavior,
// (probably an application crash).
// be careful about dereferencing null pointers in code (DON'T)
