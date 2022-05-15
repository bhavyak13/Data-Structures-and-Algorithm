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
int *explored,*dis,*low,*parent,*ans;
int tym=1;
void dfs(int ind,vector<vector<int>>graph){
    if(explored[ind]==1)return;
    int numofchild=0;
    explored[ind]=1;
    low[ind]=dis[ind]=tym++;
    vfor(graph[ind]){
        if(explored[*i]==1&&*i!=parent[ind])
            low[ind]=min(low[ind],dis[*i]);//why dis
        if(explored[*i]==0){
            numofchild++;
            parent[*i]=ind;
            dfs(*i,graph);
            low[ind]=min(low[ind],low[*i]);
        }
    }
    if(parent[ind]==-1){
        if(numofchild>1)ans[ind]=1;
        return;
    }
    if(low[ind]>=dis[parent[ind]]){
        ans[parent[ind]]=1;
    }
}
void solve()
{
    in2(v,e);

    vector<vector<int>>graph(v+1);

    ffor(i,0,e){
        in2(x,y);
        graph[x].pb(y);
        graph[y].pb(x);
    }

    explored=new int[v+1];
    dis=new int[v+1];
    low=new int[v+1];
    parent=new int[v+1];
    ans=new int[v+1];

    ffor(i,0,v+1)ans[i]=0;
    ffor(i,0,v+1)explored[i]=0;
    ffor(i,0,v+1)parent[i]=-1;

    dfs(1,graph);

    // cout<<endl;
    // ffor(i,1,v+1){
    //     pt(parent[i]);
    // }cout<<endl;
    // ffor(i,1,v+1){
    //     pt(dis[i]);
    // }cout<<endl;
    // ffor(i,1,v+1){
    //     pt(low[i]);
    // }cout<<endl;
    ffor(i,0,v+1){
        if(ans[i])cout<<i<<" ";
    }
    // mem(parent,-1);
    // mem(low,INT_MAX);

    // int tym=1;
    // stack<int>stk;
    // stk.push(1);
    // while(!stk.empty()){
    //     int x=stk.top();
    //     stk.pop();
    //     if(explored[x])continue;
    //     dis[x]=tym++;
    //     low[x]=dis[x];
    //     explored[x]=1;
    //     vfor(graph[x]){
    //         if(!explored[*i]){stk.push(*i);parent[*i]=x;}
    //     }
    // }
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