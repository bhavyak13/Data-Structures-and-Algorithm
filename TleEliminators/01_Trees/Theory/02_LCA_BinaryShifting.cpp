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

void dfs(int root,int prnt,vvi& g,vvi&parent){
    vfor(g[root]){
        if(*itr!=prnt){
            parent[*itr][0]=root;
            dfs(*itr,root,g,parent);
        }
    }
}

int kthParent(int vertx,vvi&prnt,int k){
    for(int i=0;i<=log2(vertx)+1;i++){
        if(vertx==-1)break;
        if((1<<i)&k){
            vertx=prnt[vertx][i];
        }
    }
    return vertx;
}

void fillHeight(int root,int prnt,int lvl,vi&height,vvi&g){
    vfor(g[root]){
        if(*itr!=prnt)fillHeight(*itr,root,lvl+1,height,g);
    }
    height[root]=lvl;
}

int lca(int vrtx1,int vrtx2,vi&height,vvi&parent){
    int heightVertex1=height[vrtx1];
    int heightVertex2=height[vrtx2];

    int ans=1;//enter the value where tree is rooted!

    // binary search
    int i=1,j=min(heightVertex1,heightVertex2);
    while(i<=j){
        int m=(i+j)/2;
        int x=kthParent(vrtx1,parent,heightVertex1-m);
        int y=kthParent(vrtx2,parent,heightVertex2-m);
        if(x==y){
            ans=x;
            i=m+1;
        }else{
            j=m-1;
        }
    }
    return ans;
}

int lcaLogN(int vrtx1,int vrtx2,vi&height,vvi&parent,int v){
    if(height[vrtx1]>height[vrtx2]){
        swap(vrtx1,vrtx2);
    }
    vrtx2=kthParent(vrtx2,parent,height[vrtx2]-height[vrtx1]);
    if(vrtx1==vrtx2)return vrtx1;
    for(int i=log2(v)+1;i>=0;i--){
        int prnt1=parent[vrtx1][i];
        int prnt2=parent[vrtx2][i];
        if(prnt1!=prnt2&&prnt1!=-1&&prnt2!=-1){
            vrtx1=prnt1;
            vrtx2=prnt2;
        }
    }
    return parent[vrtx1][0];
}


void solve()
{
    //vertices considered are -> on '1 based indexing'
    in(v);
    vvi g(v+1,vi());
    ffor(i,0,v-1){
        in2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    vvi parent(v+1,vi(log2(v) + 5,-1));
    //run a dfs and we can find the first parent of every node
    parent[1][0]=-1;
    dfs(1,-1,g,parent);
    //i.e now parent[x][0] is stored for every node

    //calculating remainaing parents of each node.
    //parent[x][i] = 2^ith parent of x
    for(int i=1; i<log2(v)+5; i++){
        for(int x=1;x<=v;x++){
            int intermediate=parent[x][i-1];
            if(intermediate==-1)continue;
            parent[x][i]=parent[intermediate][i-1];
        }
    }
    // LCA finding : 
    // log(n)*log(n) approach
    //preCalculating height
    vi height(v+1,0);
    fillHeight(1,-1,1,height,g);

    in(q);
    while(q--){
        in2(vrtx1,vrtx2);//enter the 2 vertex whose lca you wanna find
        cout<<lca(vrtx1,vrtx2,height,parent);//log n*log n 
        cout<<" ";
        cout<<lcaLogN(vrtx1,vrtx2,height,parent,v)<<endl;//log n
    }
}


/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}