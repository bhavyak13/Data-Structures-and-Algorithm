/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

//input full vector
template<class T>istream& operator >> (istream &is, vector<T>& V) {for(auto &e : V)is >> e;return is;}

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
bool cmp1(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
//sort map by value //increasing order
bool cmp2(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}
struct cmp {constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b)const noexcept{return a.first > b.first;}};
vector<int>factor(int n){
    vector<int>ans;
    if(!(n%2))ans.push_back(2);
    while(!(n%2))n/=2;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)ans.push_back(i);
        while(n%i==0)n/=i;
    }
    if(n>1)ans.push_back(n);
    return ans;
}


/*------------------------------------begin------------------------------------*/
#define pi pair<int,int>
priority_queue<pi>mx;
priority_queue<pi,vp,greater<pi>>mn;
int ok[4];
void fun(){
    priority_queue<pi,vp,greater<pi>>temp;
    while(!mn.empty()){
        auto p=mn.top();
        ok[p.ss]=p.ff;
        temp.push(p);
        mn.pop();
        // pt2(p.ff,p.ss);
    }
    while(!temp.empty()){
        auto p=temp.top();
        mn.push(p);
        temp.pop();
    }
}
void solve()
{
    vvi a;
    ffor(i,0,4){
        in(n);
        vi v(n);
        cin>>v;
        sort(all(v));
        mx.push({v[0],i});
        mn.push({v[0],i});
        a.pb(v);
    }
    /*
        1 0
        1 1
        2 3
        3 2
        diff = 3 - 1
        alwys chote ko bda bnaengy
    */
    int ans=im;
    while(1){
        auto f=mn.top();
        int diff=mx.top().ff-f.ff;
        if(ans>diff){
            ans=diff;
            fun();
        }
        int indx=f.ss;
        auto itr=ub(all(a[indx]),f.ff);
        if(itr==a[indx].end())break;
        pi nw={*itr,f.ss};//2,0
        mn.pop();
        mn.push(nw);
        mx.push(nw);
    }
    ffor(i,0,4){
        pt(ok[i]);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}