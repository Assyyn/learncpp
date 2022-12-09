int main() {
  int x{5};
  int *const ptr{&x}; // const after asterisk means this is a const pointer

  *ptr = 30; // ptr itself is const, but not the value it points to

  int y{20};
  // ptr = &y; // ptr is const pointer

  const int *const ptr2{&y}; // a const pointer to a const value

  return 0;
}
