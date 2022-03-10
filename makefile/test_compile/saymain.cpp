#include "say.h"
int main(int argc, char *argv[])
{
    extern Say librarysay;                       // 使用库的对象
    Say localsay = Say("Local instance of Say"); //使用库的类定义
    sayhello();                                  // 使用库的普通该函数
    librarysay.sayThis("howdy");
    librarysay.sayString();
    localsay.sayString();
    return (0);
}