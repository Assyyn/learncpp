const char* concatenateChars(char a, char b)
{
    return new char[2]{a, b};
}

int foo()
{
    return 0;
}

int main()
{
    // either use the function name without the call():
    // this is an implicit conversion
    const char* (*const charOps)(char a, char b){concatenateChars};

    // or use &foo to get a function pointer
    int (*const func)(){&foo};

    // non-const function pointers can be assigned function pointers
    int (*fcnPtr)();
    fcnPtr = &foo;

    // a common mistake:
    // fcnPtr = foo(); // error: fcnPtr expects value of type int(*)(),
    // cannot assign value of type int

    // function pointers can be assigned value nullptr
    fcnPtr = nullptr;
}