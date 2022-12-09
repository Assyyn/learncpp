#include <iostream>

void testPtr(int *ptr) { // function to test if a pointer is null
  if (ptr == nullptr) {
    std::cout << "null pointer, can't access value.\n";
  } else {
    std::cout << *ptr << '\n';
  }
}

int main() {
  int *ptr{};  // null pointer
  int *ptr2{}; // null pointer

  int x{3};
  ptr2 = &x;

  testPtr(ptr);

  testPtr(ptr2);

  testPtr(nullptr);

  int *ptr3{&x};
  if (ptr3) // evalutes to a boolean. if ptr3 points to something, returns true
  {
    std::cout << *ptr3 << '\n'; // 3
  }

  return 0;
}
