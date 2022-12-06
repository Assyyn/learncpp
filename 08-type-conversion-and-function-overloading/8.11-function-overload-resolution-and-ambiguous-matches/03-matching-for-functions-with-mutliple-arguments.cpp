#include <iostream>

// If there are multiple arguments, the compiler applies the matching rules to each argument in turn.
// An illustration:

void print(char x, int y)
{
}

void print(char x, float y)
{
}

void print(char x, char y)
{
}

void print(char x, double y)
{
}

int main()
{
    print('a',3.0f);    // exact match: char,float
    print('a',true);    // promotion of bool value to int
}