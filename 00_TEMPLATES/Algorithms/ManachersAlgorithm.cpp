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
#define N "NO" 

// #define int long long

/*
    x [a b a d a b a] d
    0 [1 2 3 4 5 6 7] 8 
dp[i]  1 2 1 4 1    
       l M   x   i r    
            mirror of y  -> r-y+l
*/
/*------------------------------------begin------------------------------------*/

/*

even : 
    d[2*i] = 2 * d2[i] + 1
odd :
    d[2*i+1] = 2 * d1[i]

*/

/*
1. i is the index of the center letter of the current palindrome.
2. if size of palindrome centered at i is x, then dp[i] stores (x+1)/2;
*/

vector<int> manacher_odd(string s){
    s="$"+s+"^";
    int n=s.size();
    int l=1,r=1;
    vector<int> dp(n,1);
    ffor(i,0,n){
        int mirror=l+(r-i);
        dp[i]=max(0,min(dp[r-i],dp[mirror]));
        while(s[i+dp[i]]==s[i-dp[i]])dp[i]++;
        if(i+dp[i]>r){
            r=i+dp[i];l=i-dp[i];
        }
    }
    return vector<int>(dp.begin()+1,dp.end()-1);
}
vector<int> manacher(string s){
    string t;
    for(auto c:s){
        t+=string("#")+c;
    }
    auto res=manacher_odd(t+"#");
    return vector<int>(begin(res),end(res));
    // return vector<int>(begin(res)+1,end(res)-1);
}
void solve(){
    string s;
    cin>>s;
    vector<int> d=manacher(s);
    int n=s.size();
    vector<int> dp(n);
    if(n%2){ // odd
        for(int i=0;i<n;i++){
            dp[i]=d[2*i+1]-1;
            pt(dp[i]);
        }
    }else{
        for(int i=0;i<n;i++){
            dp[i]=d[2*i]-1;
            pt(dp[i]);
        }
        // if i & i-1 are center, then length of longest palindrom with center as i, i-1 is given by dp[i];
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    // mahadev;
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}