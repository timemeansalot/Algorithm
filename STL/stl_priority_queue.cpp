// priority queue keap a *heap structure* so it requires *randomo access iterator*
// aout its container. Only Vector and Deque can support that.
// Default container for priority queue is Vector

#include <iostream>
#include <queue>

using namespace std;

class mycomparison
{
private:
    bool reverse;

public:
    mycomparison(const bool &revparam = false)
    {
        reverse = revparam;
    }

    bool operator()(const int &lhs, const int &rhs) const
    {
        if (reverse)
            return (lhs > rhs);
        else
            return (lhs < rhs);
    }
};

void priority_queue_init()
{
    int myints[] = {10, 60, 50, 20};
    priority_queue<int> first;
    first.push(2);
    priority_queue<int> second(myints, myints + 4);                           // top is the biggest value
    priority_queue<int, vector<int>, greater<int>> third(myints, myints + 4); // top is the smallest value

    cout << "first top: " << first.top() << endl;
    cout << "second top: " << second.top() << endl;
    cout << "third top: " << third.top() << endl;

    priority_queue<int, vector<int>, mycomparison> fourth; // default is false
    priority_queue<int, vector<int>, mycomparison> fifth(mycomparison(true));

    fourth.push(1);
    fourth.push(2);
    fourth.push(1);
    fourth.push(1);
    cout << "fourth top: " << fourth.top() << endl;
    cout << "fourth size: " << fourth.size() << endl;

    fifth.push(1);
    fifth.push(2);
    fifth.push(1);
    fifth.push(1);
    cout << "fifth top: " << fifth.top() << endl;
}

int main()
{
    priority_queue_init();
    return 0;
}
