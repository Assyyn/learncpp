#include <iostream>

void nullPtrTest(int *ptr) {
  if (!ptr)
    std::cout << "null pointer\n";
}

int main() {
  int *ptr{};
  nullPtrTest(ptr);

  ptr = NULL;
  nullPtrTest(ptr);

  ptr = 0;
  nullPtrTest(ptr);

  return 0;
}

// as seen after execution, NULL and 0 can also be used to assign a null value
// to a pointer (i.e. make it a null pointer), but you should avoid them in
// modern C++.
//
// as a side note, prefer references over pointers unless the additional
// capabilities provided by pointers are needed - as those are harder to mess up
