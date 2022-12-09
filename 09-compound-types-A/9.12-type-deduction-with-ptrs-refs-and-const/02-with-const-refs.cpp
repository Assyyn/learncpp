#include <string>

const std::string &getConstRef();
// some function that returns a const reference

int main() {
  auto ref1{getConstRef()}; // std::string (reference dropped)
                            // then top-level const dropped from result

  const auto ref2{getConstRef()}; // const std::string
                                  // reapply const, reference dropped

  auto &ref3{getConstRef()}; // const std::string&
                             // reapply reference, low-level const not dropped

  const auto &ref4{getConstRef()}; // const std::string&
                                   // reapply const and reference
  // if you want a const reference,
  // reapply the const qualifier even when it's not strictly necessary,
  // as it helps prevent mistakes

  return 0;
}
