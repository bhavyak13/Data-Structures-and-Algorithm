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
#define V 5
// int graph[V][V];
int fun(int initial,int curr,int *sett,int graph[][V]){
    auto k=true;
    ffor(i,1,V+1){
        if(sett[i]==0){k=false;break;}
    }
    if(k)return graph[curr][initial];
    int ans=INT_MAX;
    ffor(i,1,V+1){
        if(sett[i]==0){
            sett[i]=1;
            int a=graph[curr][i]+fun(initial,i,sett,graph);
            sett[i]=0;
            ans=min(a,ans);
        }
    }
    return ans;
}
void solve()
{
    // in2(v,e);
    int v=4;
    // V=v+1;
    int graph[5][5]={ {0 ,0, 0, 0, 0 },
                       {0, 0, 10, 15, 20 },
                       { 0,10, 0, 35, 25 },
                       { 0,15, 35, 0, 30 },
                       { 0,20, 25, 30, 0 } };
    //                 //    ans=80
    // int graph[5][5]={ {0 ,0, 0, 0, 0 },
    //                    {0, 0, 10, 15, 20 },
    //                    { 0,5, 0, 9, 10 },
    //                    { 0,6, 13, 0, 12 },
    //                    { 0,8, 8, 9, 0 } };
                    //    ans=35

    // mem(graph,0);
    // ffor(i,0,e){
    //     in3(x,y,cost);
    //     graph[x][y]=cost;
    // }
    int ans=INT_MAX;
    int set[5]={0};
    ffor(i,1,v+1){
        set[i]=1;
        ans=min(ans,fun(i,i,set,graph));
        set[i]=0;
    }
    pn(ans);
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