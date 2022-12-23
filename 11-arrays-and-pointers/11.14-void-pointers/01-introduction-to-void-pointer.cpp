int main()
{
    void* ptr; // ptr is a void pointer

    struct Something
    {
        int n;
        float f;
    };

    // a void pointer can point to objects of any data type, therefore it is
    // also known as the generic pointer
    int nValue;
    float fValue;
    Something sValue;

    ptr = &nValue; // valid
    ptr = &fValue; // valid
    ptr = &sValue; // valid

    return 0;
}