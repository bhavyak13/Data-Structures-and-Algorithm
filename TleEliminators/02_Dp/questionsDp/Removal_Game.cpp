// /*
//     Author : Bhavya Kawatra
//  Institute : MAIT
//       Dept : CST
//      Email : bhavyakawatra6@gmail.com
//  CF handle : BhavyaKawatra13
// */
// #include <bits/stdc++.h>
// using namespace std;

// #define db double
// #define im INT_MAX
// #define ll long long
// #define mod 1000000007
// #define vi vector<int>
// #define vvi vector<vi>
// #define vp vector<pair<int,int>>
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define T true
// #define F false
// #define mem(x, y) memset(x, y, sizeof(x))
// #define sp(x) cout << fixed;cout << setprecision(x)
// #define sz size()
// #define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define PI 3.14159265358979323846
// #define lb lower_bound
// #define ub upper_bound
// #define bs binary_search
// #define full_line(s) getline(cin, s)
// #define in(n) int n;cin >> n
// #define in2(a, b) int a,b;cin >> a >> b
// #define in3(a, b, c) int a,b,c;cin >> a >> b >> c
// #define in4(a, b, c,d) int a,b,c,d;cin >> a >> b >> c>>d
// #define max_heap(pq) priority_queue <int> pq
// #define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq
// #define asort(v) sort(v.begin(),v.end())
// #define dsort(v) sort(v.rbegin(),v.rend())
// #define pn(p) cout<<p<<endl
// #define pt(p) cout<<p<<" "
// #define pt2(p,q) cout<<p<<" "<<q<<endl
// #define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl
// #define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl
// #define vfor(v) for (auto itr =v.begin() ; itr!=v.end(); itr++)
// #define vbfor(v) for (auto itr =v.rbegin() ; itr!=v.rend(); itr++)
// #define ffor(i, a, b) for (int i = a; i < b; i++)
// #define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
// #define all(v) v.begin(),v.end()
// #define Y "YES" 
// #define N "NO" 
// #define int long long
// int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
// int count_digit(int n){int c = 0;while (n > 0){c++;n /= 10;}return c;}
// void maxi(int &a, int &b){if (a > b){swap(a, b);}}
// int mymin(int a, int b, int c){int mini = min(a, c);return min(mini, b);}
// int mymax(int a, int b, int c){int big = max(a, c);return max(big, b);}
// // first -> decreasing order && second -> increasing order
// bool compr(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
// //sort map by value //increasing order
// bool cmp(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
// int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}

// /*------------------------------------begin------------------------------------*/

// auto fun(){}

// void solve()
// {
//     in(n);
//     vi a(n);
//     int s=0;
//     ffor(i,0,n)cin>>a[i];
//     ffor(i,0,n)s+=a[i];
//     // dp[l][r] -> maximum value of scoreOfPlayer1-scoreOfPlayer2 in range l to r
//     // if he choose l th index then dp[l][r]=a[l]-dp[i+1][r]
//     // else if he choose r th index then dp[l][r]=a[r]-dp[l][j-1]
//     vvi dp(n+1,vi(n+1,0));
//     bfor(i,n,0){
//         ffor(j,i,n){
//             if(i==j)dp[i][j]=a[i];
//             else dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
//         }
//     }
//     // score of 1 - score of 2 = dp[0][n];
//     // score of 1 + score of 2 = sum of a[i]'s
//     // hence score of 1 = (dp[0][n] + sum) / 2
//     pn((dp[0][n-1]+s)/2);
// }

// /*-------------------------------------end-------------------------------------*/
// signed main()
// {
//     mahadev;

//     solve();
//     return 0;
// }
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

auto fun(){}

void solve()
{
    in(n);
    vi a(n);
    cin>>a;
    // dp[l][r] -> maximum value player 1 can make from l to r
    vvi dp(n+5,vi(n+5,0));
    for(int l=n;l>=1;l--){
        for(int r=l;r<=n;r++){
            if(l==r)dp[l][r]=a[l-1];
            else dp[l][r]=max(a[l-1]+min(dp[l+2][r],dp[l+1][r-1]),a[r-1]+min(dp[l][r-2],dp[l+1][r-1]));
        }
    }
    pn(dp[1][n]);
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}