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

    cout << "size: " << v.size() << endl;         // current size of vector
    cout << "capacity: " << v.capacity() << endl; // capacity of vector
    cout << "max size: " << v.max_size() << endl; // larget possible vector item

    v.resize(4); // set size to 4, this will drop the [new_size, end) item in vector
    cout << "new size: " << v.size() << endl;
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;

    // make size large again
    v.resize(5);
    cout << "large size: " << v.size() << endl;
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " "; // when we make the size of vector large again, the element at end is 0
                           // so we can confirm that the itme in vector are throw away when make size small
    cout << endl;

    if (v.empty())
        cout << "vector is empty" << endl;
    else
        cout << "vector is not empty" << endl;

    // shrink vector
    v.shrink_to_fit(); // shrink capacity, make capacity = size
        cout << "capacity after shrink: " << v.capacity() << endl;
}

void vector_access_element()
{
    
}

int main()
{
    // vector_traverse();
    // vector_capacity();
    vector_access_element();
    return 0;
}