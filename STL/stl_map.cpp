/**
 * 1. map item is in the form of (key, value)
 * 2. map item are sorted by its key
 */

#include <iostream>
#include <map>

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

using namespace std;

/**
 * @brief show all items in a STL map. STL map has two values, one is the key, the other is value
 *
 * @tparam key key type of map
 * @tparam value value type of map
 * @param m input map
 */
template <typename key, typename value>
inline void show_map(const map<key, value> m)
{
    if (m.empty())
    {
        cout << "map is empty" << endl;
        return;
    }
    cout << "map elements are: " << endl;
    // for (auto i = m.begin(); i != m.end(); i++)
    //     cout << i->first << " : " << i->second << endl;
    for (auto i : m)
        cout << i.first << " -> " << i.second << endl;
}

template <typename key, typename value, typename compare>
inline void show_map(const map<key, value, compare> m)
{
    if (m.empty())
    {
        cout << "map is empty" << endl;
        return;
    }
    cout << "map elements are: " << endl;
    // for (auto i = m.begin(); i != m.end(); i++)
    //     cout << i->first << " : " << i->second << endl;
    for (auto i : m)
        cout << i.first << " -> " << i.second << endl;
}

void map_constructor()
{
    map<char, int> m;
    m['a'] = 1;
    cout << "map size is: " << m.size() << endl;
    cout << "size of char: " << sizeof(char) << " , size of int: " << sizeof(int) << endl;
    cout << "sizeof map: " << sizeof(m) << endl;

    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;

    map<char, int> m2(m.begin(), m.end()); // range
    map<char, int> m3(m2);                 // copy constructor

    map<char, int, classcomp> m4; // use class compare

    bool (*function_ptr)(char, char) = fncomp;             // define a function pointer
    map<char, int, bool (*)(char, char)> m5(function_ptr); // use function pointer as compare

    show_map(m);
    show_map(m2);
    show_map(m3);
    show_map(m4);
    show_map(m5);
}

void map_access_item()
{
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;

    cout << "access by [key]: " << m['a'] << endl;
    cout << "access by at: " << m.at('b') << endl;
}

void map_modify()
{
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;

    show_map(m);

    m.insert(pair<char, int>('f', 6)); // insert using pair
    show_map(m);

    m.erase('a');
    show_map(m);

    map<char, int>::iterator it;
    it = m.find('c'); // find by key
    cout << "find(c): " << it->first << " -> " << it->second << endl;

    cout << "count(c): " << m.count('c') << endl; // count by key
    cout << "lower_bound: " << m.lower_bound('c')->first << " -> " << m.lower_bound('c')->second << endl;
    cout << "upper_bounds: " << m.upper_bound('c')->first << " -> " << m.upper_bound('c')->second << endl;
}

int main()
{
    // map_constructor();
    // map_access_item();
    map_modify();
    return 0;
}