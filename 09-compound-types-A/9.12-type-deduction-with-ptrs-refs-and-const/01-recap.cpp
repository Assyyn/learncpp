#include <string>

// recap

std::string &getRef() {
  static std::string message{"Hi!"};
  return message;
}

int main() {
  const int x{20};
  auto y{x}; // drops const

  const auto z{y}; // z is const int, (reapplied to auto deduced type)

  auto ref{getRef()};   // std::string (reference dropped)
  auto &ref2{getRef()}; // std::string& (reapplied)

  // top-level const : const that applies to the object itself
  const int a{};      // applies to itself, top-level
  int *const ptr{&y}; // applies to itself, top-level

  // low-level const : const that applies to the object being referenced or
  // pointed to
  const int *ptr2{&y};
  const int &ref3{x};

  return 0;
}

// type deduction only drops top-level consts.
