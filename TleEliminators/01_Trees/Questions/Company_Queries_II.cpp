/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define in(n) int n;cin >> n
#define in2(a, b) int a,b;cin >> a >> b
#define pn(p) cout<<p<<endl
#define pt(p) cout<<p<<" "
#define vfor(v) for (auto itr =v.begin() ; itr!=v.end(); itr++)
#define vbfor(v) for (auto itr =v.rbegin() ; itr!=v.rend(); itr++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(),v.end()
#define Y "YES" 
#define N "NO" 
#define int long long

/*------------------------------------begin------------------------------------*/
int timer,v,l;
vvi g,prnt;
vi inTime,outTime,height;

void dfs(int root,int parent,int lvl){
    inTime[root]=++timer;
    prnt[root][0]=parent;
    for(int i=1;i<=l;i++){
        int intermediate=prnt[root][i-1];
        if(intermediate!=-1)
        prnt[root][i]=prnt[intermediate][i-1];
    }
    vfor(g[root]){
        if(*itr!=parent){
            dfs(*itr,root,lvl+1);
        }
    }
    height[root]=lvl;
    outTime[root]=++timer;
}

void preprocess(){
    timer=0;
    l=ceil(log2(v));
    inTime.resize(v+1);
    outTime.resize(v+1);
    height.resize(v+1);
    prnt.assign(v+1,vi(l+1,-1));
    dfs(1,-1,1);
}

//is vrtx1 ancestor of vrtx2?
bool isAncestor(int vrtx1,int vrtx2){
    return inTime[vrtx1]<=inTime[vrtx2] && outTime[vrtx1]>=outTime[vrtx2];
    //equal in case of vrtx1==vrtx2
}

int lca(int vrtx1,int vrtx2){
    if(isAncestor(vrtx1,vrtx2)){
        return vrtx1;
    }
    else if(isAncestor(vrtx2,vrtx1)){
        return vrtx2;
    }
    for(int i=l;i>=0;i--){
        if(prnt[vrtx1][i]!=-1)
        if(!isAncestor(prnt[vrtx1][i],vrtx2)){
            vrtx1=prnt[vrtx1][i];
        }
    }
    return prnt[vrtx1][0];
}

void solve()
{
    cin>>v;
    in(q);
    g.assign(v+1,vi());
    ffor(i,2,v+1){
        in(x);
        g[i].pb(x);
        g[x].pb(i);
    }
    preprocess();
    //queries answerPart!
    ffor(i,0,q){
        in2(x,y);
        pn(lca(x,y));
    }
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}