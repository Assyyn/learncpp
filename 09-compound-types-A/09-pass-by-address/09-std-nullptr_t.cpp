#include <cstddef> // for std::nullptr_t
#include <iostream>

// case: when you want a function that only accepts nullptr

void print(std::nullptr_t) { std::cout << "in print(std::nullptr_t)\n"; }

void print(int *ptr) { std::cout << "in print(int*)\n"; }

int main() {
  int x{2};
  int *ptr{&x};

  print(ptr); // print(int*)

  print(nullptr); // print(std::nullptr_t), nullptr is of type std::nullptr_t
                  // because it is a direct match

  ptr = nullptr; // ptr is now a null pointer
  print(ptr);    // print(int*) because ptr is of type int*,
                 // no ambiguity is possible (because types don't change)

  return 0;
}
