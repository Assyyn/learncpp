#include <cassert>
#include <iostream>

enum class Type
{
    tInt,
    tFloat,
    tCString,
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
        case Type::tInt:
            // cast to int pointer and perform indirection
            std::cout << *(static_cast<int*>(ptr)) << '\n';
            break;
        case Type::tFloat:
            // cast to float pointer and perform indirection
            std::cout << *(static_cast<float*>(ptr)) << '\n';
            break;
        case Type::tCString:
            // cast to char pointer (no indirection)
            std::cout << static_cast<char*>(ptr) << '\n';
            break;
        default:
            assert(false && "type not found");
            break;
    }
}

int main()
{
    int nValue{5};
    float fValue{5.3f};
    char szValue[]{"Mollie"};

    printValue(&nValue, Type::tInt);
    printValue(&fValue, Type::tFloat);
    printValue(&szValue, Type::tCString);

    // we could, however, do things that make no sense and the compiler would
    // not complain about it(as there is no type checking)!
    printValue(&nValue, Type::tCString);
    // what will it print, and why would you ever use it?

    return 0;
}