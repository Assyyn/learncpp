#include <iostream>

auto derefPtr(const int *ptr) -> void {
  if (ptr) {
    std::cout << *ptr << '\n';
  }
}

int main() {
  const int x{5};
  const int *ptr{&x}; // okay: ptr is pointing to a "const int"

  derefPtr(ptr);

  // *ptr = 6; // not allowed: we can't change a const value

  const int y{10};
  ptr = &y; // allowed: the pointer itself is not const; so we can make it point
            // to something else instead

  derefPtr(ptr);

  int z{22};
  ptr = &z; // ptr points to 'const int', z is now treated as a const when
            // accessed through ptr

  derefPtr(ptr);

  // *ptr = 90; // ptr points to 'const int' and therefore won't allow modifying
  // through it
  z = 90; // z is still just an int however

  derefPtr(ptr);

  return 0;
}
