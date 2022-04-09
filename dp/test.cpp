#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 1); // init a vector which has 10 items, each item is 1
    int n = 5, capacity = 10;
    std::vector<std::vector<int>> maxValue(n + 1, std::vector<int>(capacity + 1, 0));
    for (auto i : maxValue)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout<<"hello world"<<endl;
    return 0;
}
