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

auto fun(){}

void solve()
{
    in2(v,k);
    vvi g(v+1,vi());
    ffor(i,0,v-1){
        in2(x,y);
        g[x].pb(y);
        g[y].pb(x);
    }
    // map<int,int>degNodes;
    // ffor(i,1,v+1){
    //     degNodes[g[i].sz]++;
    // }
    // int ans=0;
    // for(auto i:degNodes){
    //     if(i.ff>2){ans+=(i.ff-2)*(i.ss);}
    // }
    // auto ok=T;
    // // this solution is AC , wht I have done in this is
    // // I calculated the number of nodes whose degree is greater than or
    // // equal to 3 ,wht I thought was to see tree as a star and ignore all
    // // nodes which are conncted to less thn = to 2 edges -0- or -0 
    // // nd then see the maximum deg node as root having ans edges 
    // // see it like a ball in middle with lot of spike 
    // // ball as root nd spikes as its edges
    // // now logically diameter can include any two of these
    // // hence we will distrubite k weight equally among these spikes
    // // and our ans would be sum of weight of any 2 spikes
    // // nd bcz weight is equal therefore ans would be 2*(weight of spike)
    // if(!ans){
    //     sp(18);
    //     pn((long double) k);
    //     return;
    // }
    // ans+=2;
    // long double x=((long double)k/(long double)ans);
    // sp(18);
    // pn(x*2);

    // Editorial solution : 
    // count the number of leaf nodes in the tree
    // and we will distribute the weight equally to edges connected to leaf!
    // and here idea is still same any 2 of leaves can be in diameter
    // hence ans=2*weight on leaf node
    int ans=0;
    vfor(g){
        if((*itr).sz==1)ans++;
    }
    sp(18);
    long double x=((long double)2*k/(long double)ans);
    pn(x);
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    // mahadev;

    solve();
    return 0;
}