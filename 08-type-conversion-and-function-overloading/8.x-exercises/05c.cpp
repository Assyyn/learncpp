#include <iostream>

// Write a function template named sub that allows the user to subtract two values of different types.
auto sub(auto x, auto y)
{
    return x - y;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}