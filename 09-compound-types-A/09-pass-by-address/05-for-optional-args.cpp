#include <iostream>
#include <string>
#include <string_view>

namespace ByAdress {

void greet(std::string *name = nullptr) {

  std::cout << "Hello ";

  std::cout << (name ? *name : "guest") << '\n';
}

} // namespace ByAdress

void greet1(std::string_view name) { std::cout << "Hello" << name << '\n'; }

void greet1() { greet1("Guest"); }

int main() {
  ByAdress::greet(); // we don't know who the user is yet

  std::string joe{"Joe"};
  ByAdress::greet(&joe); // we know the user is joe

  greet1();

  greet1(joe);
  return 0;
}

// however, function overloading is a better alternative in many cases
// like the implementation of greet1()
// which has many advantages like:
// - not having to worry about null dereferences
// - and we could pass in a string literal(rvalue) if we want
