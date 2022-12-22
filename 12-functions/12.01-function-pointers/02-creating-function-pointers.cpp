int foo()
{
    return 10;
}

// note that int* fcnName() would mean a forward declaration for a function
int* fcnName();

int main()
{
    // fcnPtr is a function pointer that points to a function that takes no
    // arguments and returns an int

    // syntax: | return-type (*pointer-name) (argument1, argument2,...);
    int (*fcnPtr)();

    // compare can point to a function that takes two int and returns an int
    int (*compare)(int, int);

    // const function pointer:
    // initialization is covered in the next lesson
    int (*const fcnGreater)(){foo};

    return 0;
}