#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Use iterator to loop through all elements in vector
 */
template <typename T>
inline void show_vector(const vector<T> v)
{
    cout << "elements in vector are: ";
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;
}
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
    show_vector(v);

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
    vector<int> v;

    for (int i = 1; i <= 10; i++)
        v.push_back(i * 10);
    show_vector(v);

    cout << "reference operator v[]: " << v[2] << endl;
    cout << "at(n): " << v.at(2) << endl;
    cout << "front: " << v.front() << endl;
    cout << "back: " << v.back() << endl;

    int *pos = v.data(); // pointer to the first element
    cout << "the first item: " << *pos << endl;
}

void vector_modify()
{
    vector<int> v;
    v.assign(5, 10); // (size,value)
    show_vector(v);

    // insert at end
    v.push_back(15);
    cout << "add 15 at end, ";
    show_vector(v);

    // remove last item
    v.pop_back();
    cout << "remove item at end, ";
    show_vector(v);

    // insert at beginning
    v.insert(v.begin(), 5);
    cout << "insert 5 at beginning, ";
    show_vector(v);

    // remove item at beginning
    v.erase(v.begin());
    cout << "remove item at beginning, ";
    show_vector(v);

    // insert at beginning
    v.emplace(v.begin(), 5);
    cout << "emplacy 5 at beginning, ";
    show_vector(v);

    // insert 20 at back
    v.emplace_back(20);
    cout << "emplace 20 at back, ";
    show_vector(v);

    // erase whole vector
    v.clear();
    cout << "clean whole vector, ";
    show_vector(v);
    cout << "vector size after clean: " << v.size() << endl;

    // two vectors to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    show_vector(v1);
    show_vector(v2);

    v1.swap(v2); // swap v1 v2
    cout << "v1 and v2 after swap" << endl;
    show_vector(v1);
    show_vector(v2);
}

int main()
{
    // vector_traverse();
    // vector_capacity();
    // vector_access_element();
    vector_modify();
    return 0;
}