/*
Author : Bhavya Kawatra! 
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
#define SP(x) setprecision(x)
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
#define in(n)    \
    long long n; \
    cin >> n;
#define in2(a, b)   \
    long long a, b; \
    cin >> a >> b;
#define in3(a, b, c)   \
    long long a, b, c; \
    cin >> a >> b >> c;
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
long long count_digit(long long n)
{
    long long c = 0;
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

/*-----------------begin---------------*/
int binarys(int *arr, int key, int size)
{
    int l = 0, h = size - 1,mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;
        if (key < arr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int Rbinary(int *arr, int l, int h, int key)
{
    if (l == h)
    {
        if (arr[l] == key)
            return l;
        else
            return -1;
    }
    int mid = (l + h) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (key < arr[mid])
    {
        return Rbinary(arr, l, mid - 1, key);
    }
    else
        return Rbinary(arr, mid + 1, h, key);
}
void solve()
{
    int n = 5;
    int *arr = new int[5];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }
    cout << binarys(arr, 0, 5) << endl;
    cout << Rbinary(arr, 0, 4, 45) << endl;
    cout << Rbinary(arr, 0, 4, 10) << endl;
    delete[] arr;
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