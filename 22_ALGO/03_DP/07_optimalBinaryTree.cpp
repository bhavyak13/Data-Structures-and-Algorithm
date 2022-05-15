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
#define vp vector<pair<int,int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))
#define SP(x) cout << fixed;cout << setprecision(x);
#define sz(x) (int)x.size()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define getss(s) getline(cin, s);
#define in(n) int n;cin >> n;
#define arr(n) int arr[n];
#define in2(a, b) int a,b;cin >> a >> b;
#define in3(a, b, c) int a,b,c;cin >> a >> b >> c;
#define max_heap(pq) priority_queue <int> pq;
#define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq;
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end());
#define pn(p) cout<<p<<endl;
#define pt(p) cout<<p<<" ";
#define pt2(p,q) cout<<p<<" "<<q<<endl;
#define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define vfor(v) for (auto i =v.begin() ; i!=v.end(); i++)
#define vbfor(v) for (auto i =v.rbegin() ; i!=v.rend(); i++)
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
    if (a > b){swap(a, b);}
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
    in(n);
    int key[n+1];
    ffor(i,1,n+1){cin>>key[i];}
    int freq[n+1];
    ffor(i,1,n+1){cin>>freq[i];}
    int dp[n+1][n+1];
    mem(dp,0);
    // prefix sum array
    int psa[n+1]={0};
    ffor(i,1,n+1){
        psa[i]=psa[i-1]+freq[i];
    }
    // int root[n+1][n+1];
    // mem(root,0);
    ffor(gap,1,n+1){
        for(int i=0 ; i+gap<=n;i++){
            int j=i+gap;
            int ans=INT_MAX;
            int k=i;
            while(k<j){
                // int t=ans;
                int x=dp[i][k++]+dp[k][j];
                x+=psa[j]-psa[i];
                ans=min(ans,x);
                // if(ans!=t)root[i][j]=k;
            }
            dp[i][j]=ans;
        }
    }
    pn(dp[0][n]);
    //printing optimal binary search tree structure
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