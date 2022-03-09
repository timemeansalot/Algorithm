/* say.h */
#include <iostream>
#include <string>
void sayhello(void);
class Say
{
private:
    std::string _str;

public:
    Say(std::string str)
    {
        _str = str;
    }
    void sayThis(const char *str)
    {
        std::cout << str << " from a static library\n";
    }
    void sayString(void);
};