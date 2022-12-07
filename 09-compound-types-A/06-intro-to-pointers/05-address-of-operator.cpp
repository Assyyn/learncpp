#include <iostream>
#include <typeinfo>

int main() {
  int x{4};
  std::cout << typeid(&x).name() << '\n'; // print the type of &x

  return 0;
}

// prints 'pi' when compiled with gcc, and 'int *' on Visual Studio
