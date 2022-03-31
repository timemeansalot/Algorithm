#include <iostream>
#include <string>
using namespace std;

class food
{
public:
    food(string n) : name(n) { cout << "call constructor with param: " << n << endl; };
    food()
    {
        cout << "call constructor without param" << endl;
        name = "defaul name";
    };
    food(const food &f)
    {
        cout << "call copy constructor for: " << f.name << endl;
        name = f.name;
    }
    ~food() { cout << "call destructor for: " << name << endl; }
    void show();
    food operator=(const food &f)
    {
        cout << "call copy assignment" << endl;
        name = f.name;
        return *this;
    }
    void change(string n)
    {
        name = n;
    }

private:
    string name;
};
void food::show()
{
    cout << "food name is: " << name << endl;
}

int main()
{
    food f("apple");

    // 连续赋值
    food f1 = f;
    f1.show();

    food f2, f3;
    f2 = f3 = f;
}

/**

call constructor with param: apple
food name is: apple
call constructor without param
call constructor without param
call copy assignment
call copy assignment
call destructor for: apple
call destructor for: apple
call destructor for: apple
call destructor for: apple
call destructor for: apple
call destructor for: apple

call constructor with param: apple
food name is: apple
call constructor without param
call constructor without param
call copy assignment
call copy assignment
call destructor for: apple
call destructor for: apple
call destructor for: apple
call destructor for: apple
 */