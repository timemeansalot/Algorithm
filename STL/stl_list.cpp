#include <iostream>
#include <list>

using namespace std;

template <typename T>
inline void show_list(list<T> l)
{
    cout << "List elements are: ";
    for (auto it : l)
        cout << it << " ";
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

    cout << "max item in list: " << l.max_size() << endl;
}

void list_size()
{
    list<int> l;
    for (int i = 0; i < 5; i++)
        l.push_back(i);
    cout << "push back 5 items to list, ";
    show_list(l);

    cout << "list size: " << l.size() << endl;
    // unlike vector, List doesn't have capacity

    l.resize(3); // resize list, make size small. drop item at end
    show_list(l);
    l.resize(5); // make list size large again
    show_list(l);
}

void list_modify()
{
    list<int> l;
    l.assign(5, 10); // (size, value)
    cout << "assign 5 item, each item is 10,";
    show_list(l);

    if (l.empty())
        cout << "list is empty" << endl;
    else
        cout << "list ni not empty" << endl;

    l.insert(l.begin(), 3); // insert 3 at beginning
    show_list(l);

    // remove value in list
    l.remove(3);
    show_list(l);

    l.emplace(l.begin(), 20);
    l.emplace_front(30);
    l.emplace_back(40); // emplace will insert data in list
    show_list(l);

    // merge list
    list<int> l2{100,200,300};
    show_list(l2);
    l.merge(l2);
    show_list(l);
}

int main()
{
    // list_access_data();
    // list_size();
    list_modify();
    return 0;
}