#include <iostream>

// functions handling pointers should always check if the pointer passed is a
// null pointer

/* void print(int *ptr) {
  if (ptr) // check with conditional
    std::cout << *ptr;
} // this can result in redundant logic; let's clean it up
*/

void print(int *ptr) {
  if (!ptr) { // return early to caller if ptr is a null pointer
    return;
  }

  // if it reaches this point, it is fair to assume ptr is valid
  // no more nesting or testing required

  std::cout << *ptr;
}

int main() {
  int x{5};
  print(&x);

  int *myptr{};
  print(myptr); // note that this is still allowed. let's fix it in 03

  return 0;
}
