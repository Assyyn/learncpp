#include <iostream>

// the following function never ends, so it never gets popped off
void countDown(int count)
{
    std::cout << "push " << count << '\n';
    countDown(count - 1); // countDown() calls itself recursively
}

int main()
{
    // in my machine, the stack overflowed after counting upto -43149
    countDown(5);

    return 0;
}