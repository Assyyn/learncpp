#include <iostream>
#include <string>

const std::string &larger(const std::string &a, const std::string &b) {
  return ((a < b) ? a : b); // returns the string that
                            // comes first alphabetically
}

int main() {
  std::cout << larger("ab", "cde") << '\n';

  std::string hello{"Hello"};
  std::string world{"World"};

  std::cout << larger(hello, world) << '\n';

  return 0;
}
