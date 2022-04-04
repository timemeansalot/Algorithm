#include <iostream>
#include <deque>

using namespace std;

template <typename T>
inline void show_deque(const deque<T> dq)
{
    cout << "deque elements are: ";
    for (i : dq)
        cout << i << " ";
    cout << endl;
}


int main()
{

    return 0;
}