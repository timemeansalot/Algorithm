#include <iostream>
#include <vector>
using namespace std;

int min_length = INT_MAX;
int book[101];
int target = 0;
int init_graph[101][101];
vector<int> path;

void dfs(int current_node, int total_length)
{
    int j = 0;

    if (total_length > min_length) // if total length>min, no need to continue search
    {
        return;
    }

    // reach target node
    if (current_node == target)
    {
        if (total_length < min_length)
        {
            min_length = total_length;
            cout << "path: ";
            for (int i = 0; i <= target; i++)
            {
                cout << book[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // try from first node to last node
    for (j = 0; j <= target; j++)
    {
        if (init_graph[current_node][j] != 0 && book[j] == 0)
        {
            book[j] = current_node; // mark this node have been visited
            dfs(j, total_length + init_graph[current_node][j]);
            book[j] = 0;
        }
    }

    return;
}

int main()
{
    // void dfs(int current_node, int total_length)
    target = 4;
    for (int i = 0; i <= target; i++)
        for (int j = 0; j <= target; j++)
            init_graph[i][j] = 0;

    init_graph[0][1] = 1;
    init_graph[0][4] = 1;
    init_graph[1][2] = 3;
    init_graph[1][3] = 2;
    init_graph[2][4] = 1;
    init_graph[3][4] = 1;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < i; j++)
            init_graph[i][j] = init_graph[j][i];
    }
    for (int i = 0; i <= target; i++)
    {
        for (int j = 0; j <= target; j++)
            cout << init_graph[i][j] << " ";
        cout << endl;
    }
    dfs(0, 0);
    cout << "min length: " << min_length << endl;

    // second round
    cout << "begin second loop:" << endl;
    cout << "book: ";
    for (int i = 0; i < target+1; i++)
        cout << book[i] << " ";
    cout << endl;
    for (int i = target; i > 0;)
    {
        init_graph[i][book[i]] = 0;
        init_graph[book[i]][i] = 0;
        i = book[i];
    }
    for (int i = 0; i <= target; i++)
    {
        for (int j = 0; j <= target; j++)
            cout << init_graph[i][j] << " ";
        cout << endl;
    }

    min_length = INT_MAX;
    for (int i = 0; i <= target; i++)
        book[i] = 0;
    dfs(0, 0);
    cout << "min length: " << min_length << endl;
}