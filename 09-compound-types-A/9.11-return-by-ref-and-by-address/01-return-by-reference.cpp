#include <iostream>
#include <string>

const std::string &getProgramName() // returns a const reference
{
  static const std::string s_programName{"Calculator"}; // static std::string

  return s_programName;
}

const std::string &getAuthor() {
  const std::string author{"Makima"}; // local variable

  return author;
}

int main() {
  std::cout << "This program is named " << getProgramName() << '\n';

  // the use of this dangling reference causes undefined behavior
  std::cout << "This program was created by " << getAuthor() << '\n';

  return 0;
}

// major caveat: the object being referenced 'must' outlive the function
// returning the reference. otherwise the returned reference will be left
// dangling, resulting in undefined behavior when used
