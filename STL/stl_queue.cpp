#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

void test_queue()
{
    // the default container of queue is deque
    deque<int> dq1;
    dq1.assign({1, 2, 3});

    queue<int> q(dq1);
    cout << "queue size: " << q.size() << endl;
    q.push(20);
    cout << "first item in queue: " << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "first item in queue: " << q.front() << endl;

    if (q.empty())
        cout << "queue is empty" << endl;
    else
        cout << "queue is not empty" << endl;

    list<int> l{4, 4, 4};
    queue<int, list<int>> q2(l); // must explicitlly set the container to list
    cout << "q2 size: " << q2.size() << endl;
}

int main()
{
    test_queue();
    return 0;
}