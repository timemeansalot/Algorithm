#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
inline void show_forward_list(forward_list<T> fl)
{
    cout << "forward list elements are: ";
    for (auto i : fl)
        cout << i << " ";
    cout << endl;
}

void forward_list_capacity()
{
    forward_list<int> fl{1, 13, 4, 23, 1};

    show_forward_list(fl);

    cout << "forward list doesn't have size() function" << endl;
    cout << "forward list max size: " << fl.max_size() << endl;

    if (fl.empty())
        cout << "forward list is empty" << endl;
    else
        cout << "forward list is not empty" << endl;
}

void forward_list_modify()
{
    forward_list<int> fl;
    fl.assign(3, 10);

    show_forward_list(fl);

    fl.emplace_front(30);
    fl.push_front(30);
    show_forward_list(fl);

    fl.pop_front();
    show_forward_list(fl);

    fl.insert_after(fl.before_begin(),1100);
    fl.emplace_after(fl.begin(),1000);
    show_forward_list(fl);
    cout << "first item: " << *(fl.begin()) << endl;
    // cout << "first item: " << *(fl.end()) << endl; // illegal, can't access the last item using end()
                                                    // this is different from STL::list

}

int main()
{
    // forward_list_capacity();
    forward_list_modify();
    return 0;
}