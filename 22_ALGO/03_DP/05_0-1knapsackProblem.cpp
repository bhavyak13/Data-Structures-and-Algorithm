/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
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
void solve()
{
    in2(n, m);
    // vp v;
    int p[n + 1];
    int w[n + 1];
    p[0] = 0;
    w[0] = 0;
    ffor(i, 1, n + 1)
    {
        cin >> p[i] >> w[i];
    }
    int dp[n + 1][m + 1] = {0};
    ffor(i, 0, n + 1)
        ffor(j, 0, m + 1)
    {
        if (i == 0 || j == 0)
            dp[i][j] = 0;
        else if (j - w[i] >= 0)
            dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - w[i]]);
        //j-w[i], j->current weight! w[i]->weight of i th object!,
        // j-w[i] give index of tht object which can be inserted in knapsack as knapsack contains tht much extra space!!
        else
            dp[i][j] = dp[i - 1][j];
    }
    cout << dp[n][m];
}
/*
4 8
1 2
2 3
5 4
6 5
*/
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