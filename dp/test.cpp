#include <array>
#include <cassert>
#include <iostream>
#include <vector>

int main()
{
    std::array<int, 10> value;
    std::cout << value.size() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        value.at(i) = i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << value.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "hello world" << std::endl;
    return 0;
}