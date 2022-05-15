#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void BFS(int arr[][7], int start, int size)
{
    int visited[size + 1] = {0};
    cout << start << " ";
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 1; i < size; i++)
        {
            if (arr[x][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
}
int visited[7] = {0};
void DFS(int g[][7], int start, int size)
{

    if (visited[start] == 0)
    {
        visited[start] = 1;
        cout << start<<" ";
        for (int i = 1; i <= size; i++)
        {
            if (g[start][i] == 1 && visited[i] == 0)
            {
                DFS(g, i, size);
            }
        }
    }
}
int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(G, 3, 6);
    return 0;
}