#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 1); // init a vector which has 10 items, each item is 1
    for (auto i : v)
        cout << i << " ";
    return 0;
}