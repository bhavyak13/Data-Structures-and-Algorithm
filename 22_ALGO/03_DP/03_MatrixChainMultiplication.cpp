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
char alpha='A';
void printit(int l, int r, int s[][5])
{
    if (l == r)
    {
        cout<<alpha++;
        return;
    }
    cout<<"(";
    int y=s[l][r];
    printit(l,y,s);
    printit(y+1,r,s);
    cout<<")";
}
void solve()
{
    in(n);
    arr(n + 1);
    ffor(i, 0, n + 1) { cin >> arr[i]; }
    int dp[n + 1][n + 1] = {0};
    int x=n+1;
    x=5;
    int s[5][5] = {0};
    ffor(d, 1, n)
    {
        ffor(i, 1, n - d + 1)
        {
            int j = i + d;
            dp[i][j] = 100000;
            ffor(k, i, j)
            {
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum Multiplications: " << dp[1][n] << "\n";
    printit(1,n,s);

    // ffor(i, 1, n + 1) dp[i][i] == 0;
    // // l->chain length
    // n+=1;
    // ffor(l, 2, n)
    // {
    //     for (int i = 1; i < n; i++)
    //     {
    //         int j = i + l - 1;
    //         dp[i][j] = 100000;
    //         ffor(k, i, j)
    //         {
    //             dp[i][j] = min(dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j], dp[i][j]);
    //         }
    //     }
    // }
    // // cout << min(min(dp[i][i + 1] + dp[i + 2][i + 3], dp[i][i + 2] + arr[i] * arr[i + 2] * arr[i + 3]), arr[i - 1] * arr[i] * arr[i + 2] + dp[1 + 1][i + 3]);
    // cout << dp[1][n-1];
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