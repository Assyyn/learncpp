#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// function to find student. return nullptr if not found
const std::string *getStudent(std::vector<std::string> &myStudents,
                              std::string_view name) {
  for (auto &x : myStudents) {
    if (x == name)
      return &x;
  }

  // didn't find student, return nullptr
  return nullptr;
}

int main() {
  std::vector<std::string> classOne{"Mary", "John", "Harry"};

  std::string name{"Mary"};
  auto found{getStudent(classOne, name)};
  if (!found)
    std::cout << name << " is not a student.\n";

  std::cout << name << " is a student.\n";

  return 0;
}
