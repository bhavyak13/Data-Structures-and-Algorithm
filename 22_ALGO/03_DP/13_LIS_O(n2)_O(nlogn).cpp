/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
using namespace std;

#define db double
#define im INT_MAX
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
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
// #define arr(n) int arr[n];
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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
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
int intfloordiv(int x, int y)
{
    if (x >= 0)
        return x / y;
    else
        return (x - y + 1) / y;
}

/*-----------------begin---------------*/
//dp approach!! O(n2)
int LIS(vector<int> arr)
{
    int n=arr.size();
    int dp[n]={0};
    dp[0]=1;
    ffor(i,1,n){
        bfor(j,i,0){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        dp[i]=max(1,dp[i]);
    }
    int ans=1;
    ffor(i,0,n){
        ans=max(ans,dp[i]);
    }
    return ans;
}
//returns vector of lonest inc. subsequence! O(n2)
vi LIS2(vector<int> arr)
{
    int n=arr.size();
    int dp[n]={0};
    vector<int>p(n,-1);//parent array to print the LIS
    vi subsequence;
    dp[0]=1;
    ffor(i,1,n){
        bfor(j,i,0){
            if(arr[i]>arr[j]){
                int f=dp[i];
                dp[i]=max(dp[j]+1,dp[i]);
                if(dp[i]!=f)p[i]=j;
            }
        }
        dp[i]=max(1,dp[i]);
    }
    int ans=1,ind=1;
    ffor(i,0,n){
        if(dp[i]>ans){ans=dp[i];ind=i;}
    }
    while(p[ind]!=-1){
        subsequence.pb(arr[ind]);
        ind=p[ind];
    }
    return subsequence;
}
//dp O(n2) diff. approach!
int LIS3(vi arr){
    int n=arr.size();
    vi dp(n+1,im);
    dp[0]=-im;
    //dp[j] tells ki 'j' length ki jo inc. seq. bni hai;
    //us sequence ka last elemnt is given by dp[j]
    ffor(i,0,n){
        ffor(j,1,n+1){
            if(arr[i]<dp[j]&&arr[i]>dp[j-1]){
                dp[j]=arr[i];
            }
        }
    }
    int ans=0;
    ffor(i,1,n+1)if(dp[i]<im)ans=i;
    return ans;
}
//O(nlogn)
int LIS4(vi arr){
    int n=arr.size();
    vi dp(n+1,im);
    dp[0]=-im;
    //dp[j] tells ki 'j' length ki jo inc. seq. bni hai;
    //us sequence ka last element is given by dp[j]
    ffor(i,0,n){
        auto x=ub(dp.begin(),dp.end(),arr[i]);
        int j=x-dp.begin();//j is the index value that has to be updated!
        //j is found here in log n tym by upperbound func. which internally uses BINARY SEARCH!
        //hence tym comp. of total func. will be now nlogn!
        if(arr[i]>=dp[j-1]&&arr[i]<dp[j]){//= if duplicates are allowed!
            dp[j]=arr[i];
        }
    }
    int ans=0;
    ffor(i,1,n+1)if(dp[i]<im)ans=i;
    return ans;
}

void solve()
{
    in2(n,m);
    vi a(n),b(m);
    ffor(i,0,n)cin>>a[i];
    ffor(i,0,m)cin>>b[i];
    cout<<LIS4(a)+LIS4(b)<<endl;
}
/*-----------------end---------------*/
signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fast;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}