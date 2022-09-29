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


// Path Compressing 

class DisjointSet{
private:
    vector<int> prnt;
    vi score;
    vi rank;
    vi removal;
public:
    DisjointSet(int n){
        prnt.resize(n+1);
        for(int i=0;i<=n;i++)prnt[i]=i;
        score.assign(n+1,0);
        removal.assign(n+1,0);
        rank.assign(n+1,0);
    }
    int get(int x){
        while(x!=prnt[x])x=prnt[x];
        return x;
    }
    void merge(int x,int y){
        x=get(x),y=get(y);
        if(x==y)return;
        if(rank[x]>rank[y])swap(x,y);
        prnt[x]=y;// y <- x
        if(rank[x]==rank[y])rank[y]++;
        removal[x]+=score[y];
    }
    void addScore(int e,int exp){
        e=get(e);
        score[e]+=exp;
    }
    int getScore(int e){
        int sc=0;
        while(e!=prnt[e]){
            sc+=(score[e]-removal[e]);
            e=prnt[e];
        }
        return sc+score[e]-removal[e];
    }
};

void solve()
{
    in2(n,q);
    DisjointSet ds(n);
    while(q--){
        string s;
        cin>>s;
        if(s[0]=='a'){
            in2(e,val);
            ds.addScore(e,val);
        }else if(s[0]=='j'){
            in2(x,y);
            ds.merge(x,y);
        }else{
            in(e);
            pn(ds.getScore(e));
        } 
    }

}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}