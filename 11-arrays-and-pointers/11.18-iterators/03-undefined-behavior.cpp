#include <iostream>
#include <vector>

int main()
{
    try
    {
        std::vector array{1, 3, 5};
        for (auto i{array.begin()}; auto x : array)
        {
            std::cout << "Size: " << array.size() << '\n';
            array.erase(i);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }
}