# Converting constructors vs overloaded typecasts

Overloaded typecasts and converting constructors perform similar roles: an overloaded typecast allows us to define a function that converts some program-defined type A into some other type B. A converting constructor allows us to define a function that creates some program-defined type A from some other type B. So when should you use each?

In general, a converting constructor should be preferred to an overloaded typecast, as it allows the type being constructed to own the construction.

There are a few cases where an overloaded typecast should be used instead:

- When providing a conversion to a fundamental type (since you can’t define constructors for these types). Most idiomatically, these are used to provide a conversion to `bool` for cases where it makes sense to be able to use an object in a conditional statement.
- When providing a conversion to a type you can’t add members to (e.g. a conversion to `std::vector`, since you can’t define constructors for these types either).
- When you do not want the type being constructed to be aware of the type being converted to. This can be helpful for avoiding circular dependencies. For example, `std::string` provides an overloaded typecast to `std::string_view` so that `std::string_view` doesn’t have to `#include <string>`.

---

source: [learncpp](https://www.learncpp.com/cpp-tutorial/overloading-typecasts/)
