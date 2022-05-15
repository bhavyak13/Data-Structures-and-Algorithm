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
#define INF 10000
void relaxation(int v1, int v2, int costedge, int *cost)
{
    if (cost[v1] + costedge < cost[v2])
        cost[v2] = cost[v1] + costedge;
}
void solve()
{
    in2(v, e);
    int source = 1;
    list<pair<int, int>> arr[v + 1];
    ffor(i, 0, e)
    {
        in3(v1, v2, c);
        arr[v1].pb(mp(v2, c));
    }
    int cost[v + 1];
    ffor(i, 0, v + 1) cost[i] = INF;
    cost[source] = 0;
    ffor(k, 0, v - 1)
    {
        ffor(j, 1, v + 1)
        {
            vfor(arr[j])
            {
                relaxation(j, i->first, i->second, cost);
                // cost[i->first]=min(cost[j]+i->second,cost[i->first]);
            }
        }
    }
    ffor(i, 1, v + 1) cout << cost[i] << " ";
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
/*
TEST CASE: 
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
5 7 3
3 2 -2
3 5 1
4 3 -2
4 6 -1
6 7 3
*/