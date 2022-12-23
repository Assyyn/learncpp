// the following probably fail to allocate the array and crash, which is called
// stack overflow, mainly because it overflows the stack(memory where most
// normal variables are allocated). Stack memory for a program is generally
// quite small, so stack overflow will lead to the OS having to close down the
// program

int main()
{
    int array[1000000]; // allocate 1 million integers (probably 4MB of memory)
}