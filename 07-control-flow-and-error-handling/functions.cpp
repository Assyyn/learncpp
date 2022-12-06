#include <iostream>

int greater(int x, int y)
{
    return (x > y ? x : y);
}

int smaller(int x, int y)
{
    return (x < y ? x : y);
}

int main()
{
    // greater, smaller, greater
    int sum = greater(5, 6) + smaller(7, 9);
    int difference = greater(9, 10) - smaller(9, 20);

}