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

void initialDfs(int root,int parent,vvi &g,vvi&prnt,vi&height,int lvl){
    vfor(g[root]){
        if(*itr!=parent){
            initialDfs(*itr,root,g,prnt,height,lvl+1);
        }
    }
    prnt[root][0]=parent;
    height[root]=lvl;
}

void fillParents(vvi &g,vvi&prnt,int&totalVertices){
    for(int i=1;i<=log2(totalVertices)+1;i++){
        for(int x=1;x<=totalVertices;x++){
            int intermediate=prnt[x][i-1];
            if(intermediate!=-1)prnt[x][i]=prnt[intermediate][i-1];
        }
    }
}

int kthParent(vvi&prnt,int vrtx,int k,int& totalVertices){
    for(int i=0;i<=log(totalVertices)+1;i++){
        if((1<<i)&k){
            vrtx=prnt[vrtx][i];
        }
    }
    return vrtx;
}

void precalculations(vvi&g,int v,vvi&prnt,vi &height){
    initialDfs(1,-1,g,prnt,height,1);
    fillParents(g,prnt,v);
}

int lca(int vrtx1,int vrtx2,vvi&prnt,vi&height,int&totalVertices){
    if(height[vrtx1]>height[vrtx2]){
        swap(vrtx1,vrtx2);
    }
    vrtx2=kthParent(prnt,vrtx2,height[vrtx2]-height[vrtx1],totalVertices);
    if(vrtx1==vrtx2)return vrtx1;
    for(int i=log2(totalVertices)+1;i>=0;i--){
        int prnt1=prnt[vrtx1][i];
        int prnt2=prnt[vrtx2][i];
        if(prnt1!=prnt2&&prnt1!=-1&&prnt2!=-1){
            vrtx1=prnt1;
            vrtx2=prnt2;
        }
    }
    return prnt[vrtx1][0];
}

void solve()
{
    in2(v,q);
    vvi g(v+1,vi());
    ffor(i,0,v-1){
        in2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    vvi prnt(v+1,vi(log2(v)+2,-1));
    vi height(v+1,0);
    precalculations(g,v,prnt,height);
    ffor(i,0,q){
        in2(v1,v2);
        int lcaOfv1v2=lca(v1,v2,prnt,height,v);
        pn(abs(height[v1]+height[v2]-2*height[lcaOfv1v2]));
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}