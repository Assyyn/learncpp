#include <cstddef>
#include <cstdlib> // for NULL
#include <iostream>

// the null pointer literals 0 and NULL can cause ambiguity,
// and vary among different compilers

void print(int x) { std::cout << "print(int): " << x << '\n'; }

void print(int *ptr) {
  std::cout << "print(int*):" << (ptr ? "non-null\n" : "null\n");
}

int main() {
  int x{5};
  int *ptr{&x};

  print(ptr); // always calls print(int*)
  print(0);   // always calls print(int) because 0 is an integer literal
              // (atleast hopefully)

  // print(NULL); // can call print(int), print(int*)
  // or result in ambiguous function call compilation error
  // (clang and gcc do this)

  print(nullptr); // always calls(int*)

  return 0;
}

// print(0) resolves to print(int) over print(int*)
// NULL can have different behavior depending on the compiler
//
// nullptr will only match a pointer type
// so prefer nullptr over the other two
