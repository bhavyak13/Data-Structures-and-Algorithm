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
#define vp vector<pair<int,int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))
#define SP(x) cout << fixed;cout << setprecision(x);
#define sz(x) (int)x.size()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define getss(s) getline(cin, s);
#define in(n) int n;cin >> n;
#define arr(n) int arr[n];
#define in2(a, b) int a,b;cin >> a >> b;
#define in3(a, b, c) int a,b,c;cin >> a >> b >> c;
#define max_heap(pq) priority_queue <int> pq;
#define min_heap(pq) priority_queue <int, vector<int>, greater<int> > pq;
#define sorta(v) sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end());
#define pn(p) cout<<p<<endl;
#define pt(p) cout<<p<<" ";
#define pt2(p,q) cout<<p<<" "<<q<<endl;
#define pt3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pt4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define vfor(v) for (auto i =v.begin() ; i!=v.end(); i++)
#define vbfor(v) for (auto i =v.rbegin() ; i!=v.rend(); i++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
//#define int long long
int gcd(int a, int b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
int count_digit(int n)
{
    int c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}
void maxi(int &a, int &b)
{
    if (a > b){swap(a, b);}
}
int mymin(int a, int b, int c)
{
    int mini = min(a, c);
    return min(mini, b);
}
int mymax(int a, int b, int c)
{
    int big = max(a, c);
    return max(big, b);
}
// first -> decreasing order
// second -> increasing order
bool compr(const pair<int, int> &i1, const pair<int, int> i2)
{
    if (i1.first > i2.first)
        return true;
    if (i1.first == i2.first)
        return i1.second < i2.second;
    return false;
}



/*-----------------begin---------------*/
int *dp,n;
int **board;
bool upperleft(int x,int y){
    x--;y--;
    while(x>0&&y>0){
        if(board[x][y]==1)return false;
        x--;y--;
    }
    return true;

}
bool upperright(int x,int y){
    x--;y++;
    while(x>0&&y<(n+1)){
        if(board[x][y]==1)return false;
        x--;y++;
    }
    return true;
}
bool downleft(int x,int y){
    x++;y--;
    while(x<(n+1)&&y>0){
        if(board[x][y]==1)return false;
        x++;y--;
    }
    return true;
}
bool downright(int x,int y){
    x++;y++;
    while(x<(n+1)&&y<(n+1)){
        if(board[x][y]==1)return false;
        x++;y++;
    }
    return true;
}
vector<vector<string>>ans;
void ok(){
    vector<string>v;
    for (int i = 1; i < n+1; i++){
        string s;
        for (int j = 1; j < n+1; j++){
            if(board[i][j]==0){
                s.push_back('.');
            }else{
                s.push_back('Q');
            }
        }
        v.push_back(s);
    }
    ans.push_back(v);
}
bool check(){
    auto j=true;
    ffor(i,1,n+1){
        if(dp[i]!=0){
            j=false;
            board[i][dp[i]]=1;
        }
    }
    if(j)return j;
    bool k=true;
    ffor(i,1,n+1){
        if(dp[i]==0){break;}
        int y=dp[i];
        int x=i;
        if(upperleft(x,y)){
            if(upperright(x,y)){
                if(downleft(x,y)){
                    if(downright(x,y)){
                        k=true;
                        // break;
                    }else{k=false;break;}
                }else{k=false;break;}
            }else{k=false;break;}
        }else{k=false;break;}
    }
    if(k){
        auto v=true;
        ffor(i,1,n+1){
            if(dp[i]==0)v=false;
        }
        if(v)ok();
    }
    ffor(i,1,n+1){
        if(dp[i]!=0)
            board[i][dp[i]]=0;
    }
    return k;
}
void fun(int*set){
    auto k=check();
    if(!k)return;
    auto f=true;
    ffor(i,1,n+1){
        if(dp[i]==0)f=false;
    }
    if(f)return;
    ffor(i,1,n+1){
        if(dp[i]==0){
            if(dp[i-1]==0&&i!=1)return;
            ffor(j,1,n+1){
                if(set[j]==0){
                    dp[i]=j;
                    set[j]=1;
                    fun(set);
                    set[j]=0;
                    dp[i]=0;
                }
            }
        }
    }
}
void solve()
{
    in(n);
    ::n=n;
    board=new int*[n+1];
    ffor(i,1,n+1){
        int *temp=new int[n+1];
        ffor(j,1,n+1){
            temp[j]=0;
        }
        board[i]=temp;
    }
    dp=new int[n+1];
    int *set=new int[n+1];
    ffor(i,0,n+1)dp[i]=0;
    ffor(i,0,n+1)set[i]=0;
    fun(set);
    int g=0;
    int y=ans.size();
    while(g<y){
        for (auto i =ans[g].begin() ; i!=ans[g].end(); i++){
            cout<<*i<<endl;
        }
        cout<<endl;
        g++;
    }
}
/*-----------------end---------------*/
signed main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}