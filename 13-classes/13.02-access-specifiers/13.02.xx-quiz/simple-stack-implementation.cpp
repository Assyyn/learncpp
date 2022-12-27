/* The class should be named Stack, and should contain:

A private array of integers of length 10.
A private integer to keep track of the size of the stack.
A public member function named reset() that sets the size to 0.
A public member function named push() that pushes a value on the stack. push()
should return false if the array is already full, and true otherwise. A public
member function named pop() that pops a value off the stack and returns it. If
there are no values on the stack, the code should exit via an assert. A public
member function named print() that prints all the values in the stack.*/

#include <array>
#include <cassert>
#include <iostream>

class Stack
{
private:
    using Array = std::array<int, 10>;
    using Index = Array::size_type;

    Array m_array{};
    Index m_next{0};

public:
    void reset()
    {
        m_next = 0;
    }

    bool push(int x)
    {
        if (m_next == m_array.size())
            return false;

        m_array[m_next++] = x;
        return true;
    }

    int pop()
    {
        assert(m_next > 0 && "cannot pop empty stack");

        return m_array[--m_next];
    }

    void print()
    {
        std::cout << "( ";
        for (Index i{0}; i < m_next; ++i)
        {
            std::cout << m_array[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}