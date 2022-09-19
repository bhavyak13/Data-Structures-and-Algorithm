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


/*------------------------ Segment Tree Template begin ------------------------*/

template<typename Node,typename Update>
struct SegTree{
    int n;
    vector<int>arr;
    vector<Node>tree;
    SegTree(int a_len,vector<int>&a){
        arr=a;
        n=a_len;
        int s=1;
        while(s<2*n){
            s=s<<1;
        }
        tree.resize(s);
        fill(all(tree),Node());//starting m all Nodes will have indentity value
        build_tree(0,n-1,1);
    }
    void build_tree(int l,int r,int indx){
        if(l==r){
            tree[indx]=Node(arr[l]);
            return;
        }
        int mid=(l+r)/2;
        build_tree(l,mid,2*indx);
        build_tree(mid+1,r,2*indx+1);
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    Node query(int l,int r,int indx,int qLeft,int qRight){
        if(l>=qLeft&&r<=qRight){
            return tree[indx];
        }
        if(l>qRight||r<qLeft){
            return Node();
        }
        Node left,right,ans;
        int mid=(l+r)/2;
        left=query(l,mid,2*indx,qLeft,qRight);
        right=query(mid+1,r,2*indx+1,qLeft,qRight);
        ans.merge(left,right);
        return ans;
    }
    void update(int l, int r, int indx, int qIndx, Update&u){
        if(l==r){
            u.apply(tree[indx]);
            return;
        }
        int mid=(l+r)/2;
        if(mid>=qIndx){
            update(l,mid,2*indx,qIndx,u);
        }else{
            update(mid+1,r,2*indx+1,qIndx,u);
        }
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    void make_update(int indx,int val){
        Update new_update=Update(val);
        update(0,n-1,1,indx,new_update);
    }
    Node make_query(int left,int right){
        return query(0,n-1,1,left,right);
    }

};
struct Node1{
    int val;
    int lvl;
    Node1(){ //used during initialization and used for identity elemnt
        val=0; // -> may change
        lvl=1;
    }
    Node1(int value){ //building new nodes with this value
        val=value; // -> may change
        lvl=1;
    }
    void merge(Node1&l,Node1&r){ // l and r are child nodes
        lvl = l.lvl + 1;
        if((lvl%2))val = l.val ^ r.val;
        else val = l.val | r.val;
    }
};
struct Update1{
    int val; //store the value which was recieved during update call
    Update1(int value){ 
        val=value;
    }
    void apply(Node1&a){//applying update to given node
        a.val=val;
    }
};

/*------------------------- Segment Tree Template end -------------------------*/

void solve(){
    in2(n,q);
    n=pow(2,n);
    vi a(n);
    ffor(i,0,n)cin>>a[i];
    SegTree<Node1,Update1>seg(n,a);
    while(q--){
        in2(x,y);
        seg.make_update(x-1,y);
        pn(seg.make_query(0,n-1).val);
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}