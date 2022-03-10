#include <iostream>
#include <string>

class dog
{
private:
    std::string _name;
public:
    void speak() const;
    dog(std::string name="Tom");
};
