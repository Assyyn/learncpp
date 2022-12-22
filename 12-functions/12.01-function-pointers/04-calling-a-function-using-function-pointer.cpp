int foo()
{
    return 9;
}

int goo(int x = 10)
{
    return x * 2;
}

int main()
{
    int (*fcnPtr)(){&foo};

    // calling foo() via explicit dereference
    (*fcnPtr)();

    // calling foo() via implicit dereference
    fcnPtr();

    int (*gooPtr)(int){&goo};

    // you have to explicitly pass in the value even for the default parameters
    // while using calling functions through pointers:

    goo(); // skip passing parameter as there exists default parameter, resolved
           // at compile-time
    gooPtr(); // function pointers are resolved at runtime, default parameter
    // cannot be passed at runtime

    return 0;
}