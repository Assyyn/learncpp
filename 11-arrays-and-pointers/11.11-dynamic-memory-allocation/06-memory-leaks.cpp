// Memory leaks happen when your program loses the address of some bit of
// dynamically allocated memory before giving it back to the operating system.
// When this happens, your program can’t delete the dynamically allocated
// memory, because it no longer knows where it is. The operating system also
// can’t use this memory, because that memory is considered to be still in use
// by your program.

// some examples of memory leak incidents are given below:
void doSomething()
{
    int* ptr{new int{}};
} // ptr is destroyed here, but the memory was not freed. that memory is now
  // 'leaked'

int main()
{
    doSomething(); // memory leak example #1

    // memory leak example #2
    int value{5};
    int* ptr{new int{}}; // dynamically allocate some memory
    ptr = &value; // reassign to ptr without freeing the dynamically allocated
                  // memory

    // memory leak example #3
    int* ptr2{new int}; // dynamically allocate memory
    ptr2 = new int{};   // old address lost; leaked memory

    return 0;
}
