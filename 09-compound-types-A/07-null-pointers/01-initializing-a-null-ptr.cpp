// null pointers don't point at anything
#include <iostream>

int main() {
  int *ptr{};          // method 1, value initialize to be null pointer
  int *ptr2 = nullptr; // method 2, explicitly initialize as nullptr

  int x{4};
  ptr = &x; // ptr now points to x (no longer a null pointer)

  std::cout << *ptr << '\n'; // prints 4

  ptr = nullptr; // ptr is again a null pointer

  return 0;
}
