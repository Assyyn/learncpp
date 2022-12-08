#include <iostream>

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not
// used

void nullify([[maybe_unused]] int *ptr2) {
  ptr2 = nullptr; // make the function parameter a null pointer
}

int main() {
  int x{5};
  int *ptr{&x};

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  nullify(ptr);

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  return 0;
}

// when nullify() is called, ptr2 receives a copy of the address passed in.
// so when it changes what ptr2 points at, it only affects the copy held by ptr2
//
// it is something like passing by value some int, where the function cannot
// actually change the integer, all the changes are local
//
