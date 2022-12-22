int foo(int x)
{
    // b
    return x;
} // foo is popped off the call stack here

int main()
{
    // a
    foo(5); // foo is pushed on the call stack here
    // c

    return 0;
}

// stack at point a in program:
//-->top():     main()

// Operation: 1. foo() is pushed on the call stack, with its parameter x

// stack at point b in program:
//-->top():    foo(), x=5    // this is the stack frame for foo()
//-->           main()      // everything on top of main() is it's stack frame

// Operation: 1. foo() executes, gets popped off

// stack at point c in program:
//-->top():           main()
