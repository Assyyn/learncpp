// the syntax for function pointers is pretty ugly,
// we can fix that by using type aliases

using ValidateFunction = bool (*)(int, int);

// now instead of this:
bool validate(int x, int y, bool (*fcnPtr)(int, int)); // ew

// we can do this:
bool validate(int x, int y, ValidateFunction pfcn); // cleaner