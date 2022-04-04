#include <iostream>
#include <vector>

using namespace std;

void vector_traverse()
{
    vector<int> v;
    for (int i = 1; i < 10; i += 2)
        v.push_back(i); // add data to vector

    for (auto i = v.begin(); i != v.end(); i++) // iter from begin to end
        cout << *i << " ";
    cout << endl;

    for (auto ri = v.rbegin(); ri != v.rend(); ri++) // iter from end to begin
        cout << *ri << " ";
    cout << endl;
}

void vector_capacity()
{
    vector<int> v;
    for (int i = 1; i < 10; i += 2)
        v.push_back(i); // add data to vector

    
}

int main()
{
    vector_traverse();
    return 0;
}