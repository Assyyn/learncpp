#include <iostream>

void nullify(int *&refptr) // refptr is now a reference to a pointer
{
  refptr = nullptr; // make the function parameter a null pointer
}

int main() {
  int x{10};
  int *ptr{&x};

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

  nullify(ptr);

  std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
  return 0;
}

// a pointer to reference is impossible. references are not objects
//
