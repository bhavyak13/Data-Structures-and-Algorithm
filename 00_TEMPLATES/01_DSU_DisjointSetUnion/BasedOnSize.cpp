#include <bits/stdc++.h>
using namespace std;



// Based on Size ..
#define ll long long
vector<ll> Size;
vector<ll> prnt;
class DisjointSet{
public:
    DisjointSet(ll n){
        Size.assign(n+1,1);
        prnt.resize(n+1);
        for(int i=0;i<=n;i++)prnt[i]=i;
    }
    ll get(ll x){
        if(x==prnt[x])return x;
        return prnt[x]=get(prnt[x]);
    }
    void merge(ll x,ll y){
        x=get(x),y=get(y);
        if(x==y)return;
        if(Size[x]>Size[y])swap(x,y);
        Size[y]+=Size[x];
        prnt[x]=y;  // y <- x
    }
};
