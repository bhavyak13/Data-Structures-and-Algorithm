/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define vp vector<pair<int, int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))
#define SP(x)      \
    cout << fixed; \
    cout << setprecision(x);
#define sz(x) (int)x.size()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define getss(s) getline(cin, s);
#define in(n) \
    int n;    \
    cin >> n;
#define arr(n) int arr[n];
#define in2(a, b) \
    int a, b;     \
    cin >> a >> b;
#define in3(a, b, c) \
    int a, b, c;     \
    cin >> a >> b >> c;
#define max_heap(pq) priority_queue<int> pq;
#define min_heap(pq) priority_queue<int, vector<int>, greater<int>> pq;
#define sorta(v) sort(v.begin(), v.end());
#define sortd(v) sort(v.begin(), v.end());
#define pn(p) cout << p << endl;
#define pt(p) cout << p << " ";
#define pt2(p, q) cout << p << " " << q << endl;
#define pt3(p, q, r) cout << p << " " << q << " " << r << endl;
#define pt4(p, q, r, s) cout << p << " " << q << " " << r << " " << s << endl;
#define vfor(v) for (auto i = v.begin(); i != v.end(); i++)
#define vbfor(v) for (auto i = v.rbegin(); i != v.rend(); i++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
//#define int long long
int count_digit(int n)
{
    int c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}
void maxi(int &a, int &b)
{
    if (a > b)
    {
        swap(a, b);
    }
}
int mymin(int a, int b, int c)
{
    int mini = min(a, c);
    return min(mini, b);
}
int mymax(int a, int b, int c)
{
    int big = max(a, c);
    return max(big, b);
}
// first -> decreasing order
// second -> increasing order
bool compr(const pair<int, int> &i1, const pair<int, int> i2)
{
    if (i1.first > i2.first)
        return true;
    if (i1.first == i2.first)
        return i1.second < i2.second;
    return false;
}
/*-----------------begin---------------*/
int shortestPathVertex(int *arr, int *visited, int v)
{
    int min = INT_MAX, index;
    ffor(i, 0, v)
    {
        if (arr[i] < min && visited[i] == 0)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[][6], int source)
{
    int v = 6;
    int *dis = new int[v];
    int *visited = new int[v];
    // int visited[v] = {0};
    // queue<int> q1;
    // queue approach is wrong bcz it will not give us shortest path vertex
    // instead it willl give us vertex whose index value is less
    // whatever may be the distance it doesnt care!!
    ffor(i, 0, v)
    {
        dis[i] = 1000;
        visited[i] = 0;
    }
    dis[source] = 0;
    // q1.push(source);
    ffor(c, 0, v - 1)
    {
        int i = shortestPathVertex(dis, visited, v);
        // int i = q1.front();
        // q1.pop();
        // if (visited[i] == 0)
        visited[i] = 1;
        // else
        //     continue;
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j])
            {
                if (dis[i] + graph[i][j] < dis[j])
                {
                    dis[j] = dis[i] + graph[i][j];
                    // if (visited[j] == 0)
                    //     q1.push(j);
                }
            }
        }
    }
    ffor(i, 0, v)
    {
        if (dis[i] == 1000)
        {
            pt(i + 1);
            cout<<"NO LINK!\n";
        }else
        pt2(i + 1, dis[i]);
    }
}
void solve()
{
    // int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
    //                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //                    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    //                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    //                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int graph[6][6] =
        {
            {0, 50, 45, 10, 0, 0},
            {0, 0, 10, 15, 0, 0},
            {0, 0, 0, 0, 30, 0},
            {10, 0, 0, 0, 15, 0},
            {0, 20, 35, 0, 0, 0},
            {0, 0, 0, 0, 3, 0}};
    dijkstra(graph, 0);
}
/*-----------------end---------------*/
signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    solve();
    return 0;
}