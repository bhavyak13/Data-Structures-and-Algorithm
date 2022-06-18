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
#define vp vector<pair<int,int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define T true
#define F false
#define mem(x, y) memset(x, y, sizeof(x))
#define sp(x) cout << fixed;cout << setprecision(x)
#define sz size()
#define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define full_line(s) getline(cin, s)
#define in(n) int n;cin >> n
#define in2(a, b) int a,b;cin >> a >> b
#define in3(a, b, c) int a,b,c;cin >> a >> b >> c
#define in4(a, b, c,d) int a,b,c,d;cin >> a >> b >> c>>d
#define max_heap(pq) priority_queue <int> pq
#define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq
#define asort(v) sort(v.begin(),v.end())
#define dsort(v) sort(v.rbegin(),v.rend())
#define pn(p) cout<<p<<endl
#define pt(p) cout<<p<<" "
#define pt2(p,q) cout<<p<<" "<<q<<endl
#define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl
#define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl
#define vfor(v) for (auto itr =v.begin() ; itr!=v.end(); itr++)
#define vbfor(v) for (auto itr =v.rbegin() ; itr!=v.rend(); itr++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(),v.end()
#define Y "YES" 
#define N "NO" 
#define int long long
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
void maxi(int &a, int &b){if (a > b){swap(a, b);}}
int mymin(int a, int b, int c){int mini = min(a, c);return min(mini, b);}
int mymax(int a, int b, int c){int big = max(a, c);return max(big, b);}
// first -> decreasing order && second -> increasing order
bool compr(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
//sort map by value //increasing order
bool cmp(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

/*------------------------------------begin------------------------------------*/

int sum=0;
int dfs(vvi& g,int root,int prnt,int dist,vi&subtreeSize){
    int cnt=0;
    vfor(g[root])
        if(*itr!=prnt){
            cnt+=dfs(g,*itr,root,dist+1,subtreeSize)+1;
        }
    sum+=dist;
    return subtreeSize[root]=cnt;
}
void dfs2(vvi&g,int root,int prnt,vi&ans,int v,vi&subtreeSize){
    vfor(g[root]){
        if(*itr!=prnt){
            ans[*itr]=ans[root]-(2*subtreeSize[*itr])+(v-2);
            dfs2(g,*itr,root,ans,v,subtreeSize);
        }
    }
}
/*
ans[*itr]=(ans[root]-(subtreeSize[*itr]) )+ (v-2-subtreeSize[*itr]);
ans[*itr]=ans[root]-(2*subtreeSize[*itr])+(v-2);
wht we will do is we'll find the ans from any one vertex by doing dfs and adding distance of tht 
node from every other node
for 1st node its simple to do just dfs
now for the rest of nodes we will calculate thie subtree sizes
next what we observed is as we have got the ans. to any one random node (lets say this node is 1)
so we got ans for 1 , now how to get ans for its neighbour node(lets say it as node 3)
for node 3,
the number of nodes tht are under subtree of node 3 has a distance of one minus the distance 
node 1 has form them ! agree? bcz now for every subnode under node 3 we dont have to travel that 1-3 node path of distnace 1
hence, for the evry sub node under node 3 , we will subtract -1 from ditsance 
i.e. matematically ans tht we reduce for subnodes under 3 would be
ansSubNodes = subtreeSize[3]

now wht about other nodes that are not under subtree of 3
how many such nodes are there?
n : (total no. of nodes)
x : nodes under subtree 3
we can say there are (n-x-2) nodes for which distnce has now increased to +1?
why x-2 bcz for x nodes tht are uunder subtree 3 distance for them we have already calculated
and remaing 2 is :  1,3 distnce for them remains same!
so we'll add this value to our ans 

hnce ans[3] = ans[1] - subtreeSize[3] + (n-2-x) 
//putting value of x
therefor ans[3]=ans[1]-subtreeSize[3]+n-2-subtreeSize[3]
in general,
    ans[child]=(ans[root]-(subtreeSize[child]) )+ (v-2-subtreeSize[child]);
or  ans[child]=(ans[root]-(2*subtreeSize[child]) )+ (v-2);
*/
void solve()
{
    in(v);
    vvi g(v+1,vi());
    ffor(i,0,v-1){
        in2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    vi subtreeSize(v+1,0);
    vi ans(v+1,0);
    dfs(g,1,-1,0,subtreeSize);
    ans[1]=sum;
    dfs2(g,1,-1,ans,v,subtreeSize);
    ffor(i,1,v+1)pt(ans[i]);
    
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}
