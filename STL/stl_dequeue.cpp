#include <iostream>
#include <deque>

using namespace std;

template <typename T>
inline void show_deque(const deque<T> dq)
{
    cout << "deque elements are: ";
    for (auto i : dq)
        cout << i << " ";
    cout << endl;
}

void deque_access_data()
{
    deque<int> dq;
    dq.assign(5, 10);
    show_deque(dq);

    cout << "get data dq[2]: " << dq[2] << endl;
    cout << "get data dq.at(2): " << dq.at(2) << endl;
    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
}

void deque_size()
{
    deque<int> dq;
    dq.assign(5, 10);
    show_deque(dq);

    cout << "dq size: " << dq.size() << endl;
    dq.resize(3);
    show_deque(dq);
    dq.resize(5);
    show_deque(dq);

    if (dq.empty())
        cout << "deque is empty" << endl;
    else
        cout << "deque isn't empty" << endl;
}

void deque_modify()
{
    deque<int> dq;
    dq.assign(5, 10);
    show_deque(dq);

    dq.push_back(100);
    dq.push_front(300); // vector doesn't have push front
    show_deque(dq);

    dq.pop_back();
    dq.pop_front(); // vector doesn't have pop_front
    show_deque(dq);

    dq.erase(dq.begin());
    show_deque(dq);

    dq.emplace(dq.end(), 2222);
    dq.emplace_back(3333);
    dq.emplace_front(4444); // vector doesn't have emplace_front
    show_deque(dq);
}

int main()
{
    deque_access_data();
    // deque_size();
    // deque_modify();

    return 0;
}