#include <iostream>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

// test stack: stack is LIFO container, can only access its content which is on the top
void test_stack()
{
    deque<int> dq{1, 2, 3, 4};
    vector<int> v{1, 2, 3, 4};

    // using deque items to init stack
    stack<int> s1(dq);
    cout << "s1 size: " << s1.size() << endl;
    cout << "top item of s1: " << s1.top() << endl;

    // the first type parameter is the type of element the stack holds,
    // and the second type parameter is the container type used to implement
    // the stack.
    stack<int, vector<int>> s2(v);
    cout << "s2 size: " << s2.size() << endl;
    cout << "top item of s2: " << s2.top() << endl;
    s2.pop();
    cout << "top item of s2: " << s2.top() << endl;

    s2.push(3);
    cout << "top item of s2: " << s2.top() << endl;
    s2.emplace(44);
    cout << "top item of s2: " << s2.top() << endl;
    

}
int main()
{

    test_stack();
    return 0;
}