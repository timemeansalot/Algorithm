/**
 * 1. can't modify value in the set(The value of item is also the key to access the value)
 * 2. Every item in set is unique
 * 3. Every item in set is sorted, while in unordered_set items are not sorted
 *
 * Sets are typically implmented as binary search tree
 */

#include <iostream>
#include <set>

using namespace std;

bool fncomp(int lhs, int rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        return lhs < rhs;
    }
};

template <typename T>
inline void show_set(const set<T> s)
{
    if (s.empty())
    {
        cout << "set is empty" << endl;
        return;
    }
    cout << "set items are: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

template <typename T, typename comp>
inline void show_set(const set<T, comp> s)
{
    if (s.empty())
    {
        cout << "set is empty" << endl;
        return;
    }
    cout << "set items are: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

void set_constructor()
{
    set<int> first; // empth constructor
    int my_int[] = {1, 2, 3, 4, 5};
    set<int> second(my_int, my_int + 5);           // range
    set<int> third(second);                        // copy constructor
    set<int> fourth(second.begin(), second.end()); // iterator

    set<int, classcomp> fifth; // class as compare

    // function pointer as compare
    bool (*fn_pt)(int, int) = fncomp;
    set<int, bool (*)(int, int)> sixth(fn_pt);

    set<int> seventh = second; // copy assignment

    show_set(first);
    show_set(second);
    show_set(third);
    show_set(fourth);
    show_set(fifth);
    show_set(sixth);
    show_set(seventh);
}

void set_capacity()
{
    set<int> s{1, 2, 3, 4};
    show_set(s);

    if (s.empty())
        cout << "set is empty" << endl;
    else
        cout << "set is not empty" << endl;

    cout << "max size: " << s.max_size() << endl;
}

void set_modify()
{
    set<int> s{1, 2, 3};
    show_set(s);

    s.insert(4);
    s.insert(1);
    show_set(s);

    cout << "erase 1: " << s.erase(1) << endl;
    cout << "erase 0: " << s.erase(0) << endl;
    show_set(s);

    s.clear();
    show_set(s);
}

void set_opeartion()
{
    set<int> s{1,3,5};
    cout << "find 3 iterator: " << *(s.find(3)) << endl;
    cout << "conut 3 in set: " << s.count(3) << endl;
    cout << "find low bound iterator: " << *(s.lower_bound(3)) << endl; // 找>=value的第一个
    cout << "find high bound iterator: " << *(s.upper_bound(3)) << endl;// 找>value的第一个
    // cout << "find high bound iterator: " << (s.equal_range(3)) << endl;// 找>value的第一个

}

int main()
{
    // set_constructor();
    // set_capacity();
    // set_modify();
    set_opeartion();
    return 0;
}