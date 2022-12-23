#include <iostream>

// fortunately, using recursion termination statements in the recursive function
// can help ensure that infinite recursion does not occur
void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count - 1) // termination condition
        countDown(count - 1);
    // push keeps happening until the termination condition is met

    // pop occurs after the recursive function call, as the functions are being
    // popped off the stack
    std::cout << "pop " << count << '\n';
}

int main()
{
    countDown(10);

    return 0;
}