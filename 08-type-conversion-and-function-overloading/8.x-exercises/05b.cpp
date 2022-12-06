#include <iostream>

// Write a function template named mult that allows the user to multiply one value of any type (first parameter) and an integer (second parameter).
// The function should return the same type as the first parameter.
template <typename T>
T mult(T x, int y)
{
    return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
