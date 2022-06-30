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
//     in2(n,priceMax);
//     vi price(n),page(n);
//     ffor(i,0,n){
//         cin>>price[i];
//     }
//     ffor(i,0,n){
//         cin>>page[i];
//     }
//     /*
//         1 ≤ n ≤ 1000
//         1 ≤ x ≤ 1e6
//         1 ≤ hi,si ≤ 1000
//     */
//     vvi dp(n+1,vi(priceMax+5,0));
//     // dp[i][j] -> maximum number of pages that can be obtained from
//     // i books at j price!
//     ffor(i,1,n+1){
//         ffor(j,1,priceMax+1){
//             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             if(j>=price[i-1])
//             dp[i][j]=max(dp[i][j],dp[i-1][j-price[i-1]]+page[i-1]);
//         }
//     }
//     pn(dp[n][priceMax]);
 
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
/*
1 ≤ n ≤ 1000
1 ≤ maxPrice ≤ 1e6
1 ≤ page,price ≤ 1000
*/
auto fun(){}

//space optimised solution!
void solve()
{
    in2(n,priceMax);
    vi price(n),page(n);
    ffor(i,0,n){
        cin>>price[i];
    }
    ffor(i,0,n){
        cin>>page[i];
    }
    
    vi dp(priceMax+5,0);
    // dp[i]-> maximum number of pages that can be obtained at j price!
    ffor(i,1,n+1){
        bfor(j,priceMax+1,1){
            dp[j]=max(dp[j-1],dp[j]);
            if(j>=price[i-1])
            dp[j]=max(dp[j],dp[j-price[i-1]]+page[i-1]);
        }
    }
    pn(dp[priceMax]);

}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}