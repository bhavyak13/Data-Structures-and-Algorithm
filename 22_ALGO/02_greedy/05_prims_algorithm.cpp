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
void primAlgorithm(list<pair<int, int>> graph[], int v)
{
    int cost = INT_MAX, mv1, mv2;
    ffor(j, 0, v)
    {
        vfor(graph[j])
        {
            if (i->first < cost)
            {
                cost = i->first;
                mv1 = i->second;
                mv2 = j;
            }
        }
    }
    bool included[v] = {false};
    vector<pair<pair<int, int>, int>> ans;
    ans.pb(mp(mp(mv1, mv2), cost));
    included[mv1] = true;
    included[mv2] = true;
    int d = v;
    d -= 2;
    while (d--)
    {
        cost = INT_MAX;
        for (int k = 0; k < v; k++)
        {
            if (included[k])
            {
                vfor(graph[k])
                {
                    if (i->first < cost && !included[i->second])
                    {
                        cost = i->first;
                        mv1 = i->second;
                        mv2 = k;
                    }
                }
            }
        }
        included[mv1] = true;
        ans.pb(mp(mp(mv1, mv2), cost));
    }
    cout << "ANSWER : \n";
    int x = 0;
    vfor(ans)
    {
        pt3(i->first.first, i->first.second, i->second);
        x += i->second;
    }
    cout << "total cost : " << x << endl;
}
void solve()
{
    in2(v, e);
    list<pair<int, int>> graph[v + 1];
    ffor(i, 0, e)
    {
        in3(v1, v2, cost);
        graph[v1].pb(mp(cost, v2));
        graph[v2].pb(mp(cost, v1));
    }
    primAlgorithm(graph, v);
/*
TEST CASE
9
14
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
7 6 1
3 5 14
2 5 4
2 8 2
8 6 6
7 8 7
    
9 13
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

7 9
1 6 10
1 2 28
2 3 16
3 4 12
4 7 18
4 5 22
7 5 24
6 5 25
2 7 14

*/
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