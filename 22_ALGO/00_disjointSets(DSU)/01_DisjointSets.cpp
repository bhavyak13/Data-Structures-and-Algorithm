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
// #define int long long
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

class DSU
{
private:
    int *arr, size;

public:
    DSU(int size)
    {
        this->size = size;
        arr = new int[size+1];
        for (int i = 0; i <= size; i++)
        {
            arr[i] = -1;
        }
    }
    int find_parent(int vertex)
    {
        if (arr[vertex] < 0)
        {
            return vertex;
        }
        return arr[vertex] = find_parent(arr[vertex]);
    }
    bool unionn(int v1, int v2)
    {
        // v1 -> vertex 1
        // v2 -> vertex 2
        int pv1 = find_parent(v1);
        int pv2 = find_parent(v2);
        if (pv1 == pv2)
        {
            cout << "CYCLE DETECTED!!" << endl;
            return false;
        }
        if (arr[pv1] <= arr[pv2])
        {
            arr[pv1] += arr[pv2];
            arr[pv2] = pv1;
        }
        else
        {
            arr[pv2] += arr[pv1];
            arr[pv1] = pv2;
        }
        return true;
    }
    // void unionn(int a, int b);
};
void solve()
{
    DSU obj(8);
    obj.unionn(1, 2);
    obj.unionn(3, 4);
    obj.unionn(5, 6);
    obj.unionn(7, 8);
    obj.unionn(2, 4);
    obj.unionn(2, 5);
    obj.unionn(1, 3);
    obj.unionn(6, 8);
    obj.unionn(5, 7);
//     if (obj.find_parent(4) == obj.find_parent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";
//     if (obj.find_parent(1) == obj.find_parent(0))
//         cout << "Yes\n";
//     else
//         cout << "No\n";
}
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