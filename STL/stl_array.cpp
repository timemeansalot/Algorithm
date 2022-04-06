#include <iostream>
#include <array>

using namespace std;

template <typename T, size_t s>
inline void show_array(const array<T, s> ar)
{
    cout << "array elements are: ";
    for (auto i : ar)
        cout << i << " ";
    cout << endl;
}

void array_capacity()
{
    array<int, 5> a{1, 2, 3, 4, 5};
    show_array(a);
    a.fill(8);
    show_array(a);
    cout << "size of array: " << a.size() << endl;
    cout << "max size of array: " << a.max_size() << endl;
    if (a.empty())
        cout << "array is empty" << endl;
    else
        cout << "array is not empty" << endl;
}

void array_element_access()
{
    array<int, 5> a{1, 2, 3, 4}; // default array item is 0
    show_array(a);

    cout << "first item: " << a.front() << endl;
    cout << "last item: " << a.back() << endl;
    cout << "a[1]: " << a[1] << endl;
    cout << "a.at[2]: " << a.at(2) << endl;

    int *p = a.data(); // pointer to all data in a
    cout << "all data in array: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << *(i + p) << " ";
    }
    cout << endl;
}

void array_modify()
{
    array<int, 5> a{1, 2, 3, 4, 5};
    array<int, 5> b;
    b.fill(8); // set all item in b=8

    show_array(a);
    show_array(b);

    // swap array data
    a.swap(b);
    cout << "swap data:" << endl;
    show_array(a);
    show_array(b);
}
int main()
{
    // array_capacity();
    // array_element_access();
    array_modify();
    return 0;
}