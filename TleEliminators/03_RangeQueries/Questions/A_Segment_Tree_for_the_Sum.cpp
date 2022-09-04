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

/*------------------------------------begin------------------------------------*/

vi a;
vi seg;
void build_tree(int indx,int l,int r){
    if(l==r){
        seg[indx]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build_tree((2*indx),l,mid);
    build_tree((2*indx+1),mid+1,r);
    seg[indx]=seg[2*indx]+seg[2*indx+1];
}
void update_tree(int indx, int l, int r, int qIndx, int qVal){
    if(l==r){
        a[qIndx]=qVal;
        seg[indx]=qVal;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=qIndx){
        update_tree(2*indx,l,mid,qIndx,qVal);
    }else{
        update_tree(2*indx+1,mid+1,r,qIndx,qVal);
    }
    seg[indx]=seg[2*indx]+seg[2*indx+1];
}
int query_tree(int indx,int l,int r,int ql,int qr){
    //completely lies
    if(l>=ql&&r<=qr){
        return seg[indx];
    }
    //disjoint
    if(l>qr||r<ql){
        return 0;//identity
    }
    //overlaps
    int mid=(l+r)/2;
    int leftSum=query_tree(2*indx,l,mid,ql,qr);
    int rightSum=query_tree(2*indx+1,mid+1,r,ql,qr);
    return leftSum+rightSum;
}
void solve()
{
    in2(n,q);
    a.resize(n);
    seg.resize(4*n);
    ffor(i,0,n)cin>>a[i];
    build_tree(1,0,n-1);
    while(q--){
        in3(t,x,y);
        if(t==1){
            update_tree(1,0,n-1,x,y);
        }else{
            pn(query_tree(1,0,n-1,x,y-1));
        }
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    // mahadev;
    int t=1;
    // cin>>t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}