// std::vector can be used as a stack.To do this, we can use 3 functions that
// match our key stack operations:

// push_back() pushes an element on the stack.
// back() returns the value of the top element on the stack.
// pop_back() pops an element off the stack.

// An example program:

#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    for (auto element : stack)
    {
        std::cout << element << ' ';
    }
    std::cout << "(cap " << stack.capacity() << " length " << stack.size()
              << ")\n";
}

int main()
{
    std::vector<int> stack{};

    // we pre-allocate some memory to avoid resizing the vector a lot
    // using the reserve() function
    stack.reserve(5); // set the capacity to atleast 5

    printStack(stack);

    stack.push_back(5); // push an element on the stack
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    std::cout << "top: " << stack.back()
              << '\n'; // back() returns the last element

    stack.pop_back(); // pop_back() pops an element off the stack
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}

// these stack operations will resize the vector if more capacity is required