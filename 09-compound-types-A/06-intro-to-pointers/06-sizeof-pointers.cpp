#include <iostream>

int main() // assume a 32-bit application
{
  char *chPtr{};        // chars are 1 byte
  int *iPtr{};          // ints are usually 4 bytes
  long double *ldPtr{}; // long doubles are usually 8 or 12 bytes

  std::cout << sizeof(chPtr) << '\n'; // prints 4
  std::cout << sizeof(iPtr) << '\n';  // prints 4
  std::cout << sizeof(ldPtr) << '\n'; // prints 4

  return 0;
}

// With a 64-bit executable, a pointer would be 64-bits(8 bytes),
// as it is just a memory address, and the number of bits needed to access a
// memory address is constant
