/* say.cpp */
#include "say.h"
void Say::sayString()
{
    std::cout << _str << "\n";
}

Say librarysay("Library instance of Say");