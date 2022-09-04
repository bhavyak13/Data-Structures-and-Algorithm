// Using Ordered_Set
// /*
//     Author : Bhavya Kawatra
//  Institute : MAIT
//       Dept : CST
//      Email : bhavyakawatra6@gmail.com
//  CF handle : BhavyaKawatra13
// */
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>
// using namespace __gnu_pbds;
// using namespace std;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;

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
// bool cmp1(const pair<int, int> &i1, const pair<int, int> i2){if (i1.first > i2.first)return true;if (i1.first == i2.first)return i1.second < i2.second;return false;}
// //sort map by value //increasing order
// bool cmp2(pair<int,int>& a,pair<int, int>& b){return a.second < b.second;}
// int intfloordiv(int x,int y){if(x>=0)return x/y;else return (x-y+1)/y;}
// struct cmp {constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b)const noexcept{return a.first > b.first;}};
// vector<int>factor(int n){
//     vector<int>ans;
//     if(!(n%2))ans.push_back(2);
//     while(!(n%2))n/=2;
//     for(int i=3;i*i<=n;i+=2){
//         if(n%i==0)ans.push_back(i);
//         while(n%i==0)n/=i;
//     }
//     if(n>1)ans.push_back(n);
//     return ans;
// }


// /*------------------------------------begin------------------------------------*/

// auto fun(){}

// void solve()
// {
//     in2(n,q);
//     vi a(n);
//     ffor(i,0,n)cin>>a[i];
//     ordered_set s;
//     // 1 1 0 1 0
//     // 0 1 2 3 4
//     // 0 1 3
//     ffor(i,0,n){
//         if(a[i])s.insert(i);
//     }
//     while(q--){
//         in2(x,y);
//         if(x==2){
//             pn(*(s.find_by_order(y)));
//         }else{
//             if(a[y]){
//                 s.erase(s.ub(y));
//             }else{
//                 s.insert(y);
//             }
//             a[y]=abs(1-a[y]);
//         }
//     }
// }

// /*-------------------------------------end-------------------------------------*/
// signed main()
// {
//     mahadev;
//         solve();
    
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
void update_tree(int indx, int l, int r, int qIndx){
    if(l==r){
        a[qIndx]=abs(1-a[qIndx]);
        seg[indx]=a[qIndx];
        return;
    }
    int mid=(l+r)/2;
    if(mid>=qIndx){
        update_tree(2*indx,l,mid,qIndx);
    }else{
        update_tree(2*indx+1,mid+1,r,qIndx);
    }
    seg[indx]=seg[2*indx]+seg[2*indx+1];
}
int qry(int indx,int l,int r,int num){
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    if(num<=seg[2*indx]){
        return qry(2*indx,l,mid,num);
    }else
        return qry(2*indx+1,mid+1,r,num-seg[2*indx]);
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
    //intialization
    a.resize(n);
    seg.resize(4*n);
    //taking array values
    ffor(i,0,n)cin>>a[i];
    //building segment tree
    build_tree(1,0,n-1);
    // handling queries
    while(q--){
        in2(x,y);
        if(x==1){
            update_tree(1,0,n-1,y);
        }else{
            pn(qry(1,0,n-1,y+1));
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