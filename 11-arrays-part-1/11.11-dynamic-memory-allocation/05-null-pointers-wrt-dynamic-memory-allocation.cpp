int main()
{
    // a null pointer in the context of dynamic memory allocation, basically
    // says "no memory has been allocated to this pointer". This allows us to do
    // things like conditionally allocate memory:
    int* ptr{new int{}};

    // this does nothing as ptr is already allocated
    if (!ptr) // if ptr isn't already allocated, allocate it
        ptr = new int;

    delete ptr;
    ptr = nullptr;
    // here ptr has been deleted and is free to be allocated new memory
    if (!ptr) // if ptr isn't already allocated, allocate it
        ptr = new int;

    int* ptr2{new int};
    delete ptr2;
    ptr2 = nullptr;
    // deleting a null pointer has no effect. Thus, there is no need to check a
    // pointer before deleting
    if (ptr2)
        delete ptr2;

    // We can just delete
    delete ptr2; // delete a null pointer; has no effect
}