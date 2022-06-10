#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cout << "test queue" << endl;
    priority_queue<int> q;
    for(int i=0;i<5;i++)
        q.push(i);

    while(q.size()!=0)
    {
        cout<<q.top()<<endl;
        q.pop();
    }
}