#include "foo.h"
#include <iostream>

template <typename T>
void foo()
{
    std::cout<<"Here is foo"<<std::endl;
}

// solve undefined referrence of void foo<int>()
template void foo<int>();