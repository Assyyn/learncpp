int foo()
{
    return 10;
}

int main()
{
    int (*fcnPtr)(){&foo};
    // fcnPtr is pointing to a function:
    fcnPtr(); // fine

    fcnPtr = nullptr;
    // check before calling(dereferencing) to avoid undefined behavior
    if (fcnPtr)
        fcnPtr();

    return 0;
}