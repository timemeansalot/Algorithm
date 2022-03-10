#include "dog.h"

void dog::speak() const
{
    std::cout << "I am dog, my name is: " << _name << std::endl;
}
dog::dog(std::string name)
{
    _name = name;
}