/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
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
#define mod2 998244353
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
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
#define endl "\n"
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
#define NO "NO" 
#define int long long
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
void maxi(int &a, int &b){if (a > b){swap(a, b);}}
// first -> decreasing order && second -> increasing order
bool cmp1(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
//sort vector by second value //increasing order
bool cmp2(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
// priority_queue of pairs (min) 
#define pi pair<int,int>
struct cmp {constexpr bool operator()(pi const& a, pi const& b)const noexcept{return a.first > b.first;}};
#define ai array<int,2>
struct cmparr {constexpr bool operator()(ai const& a, ai const& b)const noexcept{return a[0] > b[0];}};
int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

// MODULO operations: 
int modmul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int modadd(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int pwr(int a, int b) {a %= mod; int res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
int binExpo(int a,int b){
    if(!b)return 1;
    int res=binExpo(a,b/2);
    if(b&1)return modmul(a,modmul(res,res));
    else return modmul(res,res);
}
// (a / b) % mod != (a% mod) / (b% mod).
// So we use Modular Multiplicative Inverse, i.e (A / B) % mod = A * ( B ^ -1 ) % mod
// for prime modulus m : (a^(m-2) = a^-1) mod m
int inv(int a){return binExpo(a,mod-2);}


/*------------------------------------begin------------------------------------

query nbumber = 4

1 -> x num
2 -> y numbers..


string s = " 3 0 "

*/

template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
        if(start > right || end < left)// disjoint
            return;
        if(start >= left && end <= right){// completely lies
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val; // may change
    ll minVal;
    Node1() { // Identity element
        val = 0;    // may change
        minVal=1e18;
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
        minVal=p1;
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = l.val + r.val;  // may change
        minVal=min(l.minVal,r.minVal);
    }
};

struct Update1 {
    ll val; // may change
    Update1(){ // Identity update
        val = 0;
    }
    Update1(ll val1) { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end) { 
        // apply update to given node
        // combine lazy value in seg tree..
        a.val += val * (end - start + 1); // may change
        a.minVal = a.minVal + val ;
    }

    void combine(Update1& new_update, int start, int end){
        // combining updates
        val += new_update.val;
    }
};

auto fun(){}

void solve()
{
    in(n);
    vi a(n);
    cin>>a;
    LazySGT<Node1,Update1>lst(n,a);
    string line;
    in(q);
    getline(cin,line);
    while(q--){
        vi nums;// 3 0 -1
        getline(cin,line);
		stringstream ss(line);
		int x;
		while(ss >> x) nums.pb(x);

        int l=nums[0],r=nums[1];
        if(nums.sz==2){
            if(l<=r){
                pn(lst.make_query(l,r).minVal);
                // pt2(lst.make_query(l,r).val,lst.make_query(l,r).minVal);
            }else{
                swap(l,r);// 0 , 3
                int f=lst.make_query(r,n-1).minVal;
                int s=lst.make_query(0,l).minVal;
                pn(min(f,s));
            }
        }else{
            int val=nums[2];
            if(l<=r){
                lst.make_update(l,r,val);
            }else{
                swap(l,r);
                lst.make_update(0,l,val);
                lst.make_update(r,n-1,val);
            }
        }
    }


}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;
    int t=1;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}










// Sieve of Eratosthenes
/*
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}


//vector<string> split(string s, char delimeter) {
//	vector <string> tokens; stringstream check1(s);
//	string intermediate;
//	while (getline(check1, intermediate, delimeter)) {
//		tokens.push_back(intermediate);
//	} 
//	return tokens;
//}

// factorize using seive

int N=10000007;
vi spf;
void seive(){
    spf.assign(N+1,1);
    for (int i = 2; i <= N; i++) {
        if (spf[i]==1) {// if i is prime
            spf[i]=i;
            for (int j = i * i; j <= N; j += i)
                if(spf[j]==1)spf[j] = i;
        }
    }
}
vi factorize(int n){
    vi ans;
    while(n>1){
        int fact=spf[n];
        ans.pb(fact);
        while(n%fact==0){
            n/=fact;
        }
    }
    return ans;
}
*/
// sum = xor + (2 * and)
/*

// NCR code
int MAXN;
vi factorial;
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % mod) % mod;
}
void precomputeFactorials(){
    MAXN=100006;// give max n here
    factorial.assign(MAXN+5,1);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }
}
*/

// vector<int>prime_factors(int n){
// 	vector<int>ans;
// 	if(!(n%2))ans.push_back(2);
// 	while(!(n%2))n/=2;
// 	for(int i=3;i*i<=n;i+=2){
// 		if(n%i==0)ans.push_back(i);
// 		while(n%i==0)n/=i;
// 	}
// 	if(n>1)ans.push_back(n);
// 	return ans;
// }