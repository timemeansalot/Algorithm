#include <iostream>
#include <list>

using namespace std;

template <typename T>
inline void show_list(list<T> l)
{
    cout << "List elements are: ";
    for (auto i = l.begin(); i != l.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void list_access_data()
{
    list<int> l;
    for (int i = 0; i < 5; i++)
        l.push_back(i);
    cout << "push back 5 items to list, ";
    show_list(l);

    for (int i = 5; i < 10; i++)
        l.push_front(i);
    cout << "push font 5 items to list, ";
    show_list(l);

    cout << "first item in list: " << l.front() << endl;
    cout << "last item in list: " << l.back() << endl;
    // can not access data by operator override[], or by at(index)
    // because data are not stored non-contiguous
}

void list_capacity()
{
    
}

int main()
{
    list_access_data();
    return 0;
}