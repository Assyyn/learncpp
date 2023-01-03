#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

// Operator() is also commonly overloaded to implement functors (or function
// object), which are classes that operate like functions. The advantage of a
// functor over a normal function is that functors can store data in member
// variables (since they are classes).

// a simple functor.
class Accumulator
{
private:
    int m_counter{0};

public:
    int operator()(int value) { return m_counter += value; }
};

#endif