#include <string>

// type deduction does not drop pointers
const std::string *name(); // function that returns pointer

int main() {
  auto ptr1{name()}; // const std::string*

  auto *ptr2{name()}; // const std::string*
                      // we can also use an asterisk with pointer type deduction
                      // auto deduces as const std::string, and then the pointer
                      // is reapplied

  auto ptr3{*name()}; // const std::string,
                      // because we dereferenced the return value

  // auto *ptr4{*name()}; // initializer is now const std::string
  // which is not a pointer

  return 0;
}

std::string *getPtr(); // function that returns a pointer

void withConstPointers() {
  const auto ptr1{getPtr()}; // std::string* const
  auto const ptr2{getPtr()}; // std::string* const
  // auto in both cases deduces to std::string*, after which
  // reapplying const makes ptr1 and ptr2 both be std::string* const

  const auto *ptr3{getPtr()}; // const std::string*
  auto *const ptr4{getPtr()}; // std::string* const
  // const auto* makes ptr3 a pointer to const std::string*
  // auto* const makes ptr4 a const pointer to std::string*
  // in essence, the order matters in such cases
}

const std::string *const getConstPtr();
// function that returns const pointer to const value

void withConstPointerToConst() {
  auto ptr1{getConstPtr()};  // const std::string*
  auto *ptr2{getConstPtr()}; // const std::string*

  const auto ptr3{getConstPtr()}; // const std::string* const
  auto const ptr4{getConstPtr()}; // const std::string* const

  const auto *ptr5{getConstPtr()};
  // const std::string*
  // (since it applies const to type deduced by auto)

  auto *const ptr6{getConstPtr()}; // const std::string* const

  // const auto const ptr7{getConstPtr()};
  // error: const qualifier cannot be applied twice
  // (consider const int const, which is illegal)

  const auto *const ptr8{getConstPtr()};
  // const std::string* const
  // because ptr8 is a pointer(guaranteed)
  // (as const int* const is valid code)
}
