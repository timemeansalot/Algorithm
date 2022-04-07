/**
 * 1. can't modify value in the multiset(The value of item is also the key to access the value)
 * 2. Every item in multiset is unique
 * 3. Every item in multiset is sorted, while in unordered_multiset items are not sorted
 *
 * multisets are typically implmented as binary search tree
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
inline void show_multiset(const multiset<T> s)
{
    if (s.empty())
    {
        cout << "multiset is empty" << endl;
        return;
    }
    cout << "multiset items are: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

template <typename T, typename comp>
inline void show_multiset(const multiset<T, comp> s)
{
    if (s.empty())
    {
        cout << "multiset is empty" << endl;
        return;
    }
    cout << "multiset items are: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

void multiset_constructor()
{
    multiset<int> first; // empth constructor
    int my_int[] = {1, 2, 3, 4, 5};
    multiset<int> second(my_int, my_int + 5);           // range
    multiset<int> third(second);                        // copy constructor
    multiset<int> fourth(second.begin(), second.end()); // iterator

    multiset<int, classcomp> fifth; // class as compare

    // function pointer as compare
    bool (*fn_pt)(int, int) = fncomp;
    multiset<int, bool (*)(int, int)> sixth(fn_pt);

    multiset<int> seventh = second; // copy assignment

    show_multiset(first);
    show_multiset(second);
    show_multiset(third);
    show_multiset(fourth);
    show_multiset(fifth);
    show_multiset(sixth);
    show_multiset(seventh);
}

void multiset_capacity()
{
    multiset<int> s{1, 2, 3, 4};
    show_multiset(s);

    if (s.empty())
        cout << "multiset is empty" << endl;
    else
        cout << "multiset is not empty" << endl;

    cout << "max size: " << s.max_size() << endl;
}

void multiset_modify()
{
    multiset<int> s{1, 2, 3};
    show_multiset(s);

    s.insert(4);
    s.insert(1);
    show_multiset(s);

    cout << "erase 1: " << s.erase(1) << endl;
    cout << "erase 0: " << s.erase(0) << endl;
    show_multiset(s);

    s.clear();
    show_multiset(s);
}

void multiset_opeartion()
{
    multiset<int> s{1, 3, 3, 5, 1};
    show_multiset(s);
    cout << "find 3 iterator: " << *(s.find(3)) << endl;
    cout << "conut 3 in multiset: " << s.count(3) << endl;
    cout << "find low bound iterator: " << *(s.lower_bound(3)) << endl;  // 找>=value的第一个
    cout << "find high bound iterator: " << *(s.upper_bound(3)) << endl; // 找>value的第一个
    // cout << "find high bound iterator: " << (s.equal_range(3)) << endl;// 找>value的第一个
}

int main()
{
    // multiset_constructor();
    // multiset_capacity();
    // multiset_modify();
    multiset_opeartion();
    return 0;
}