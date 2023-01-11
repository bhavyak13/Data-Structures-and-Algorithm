#include <bits/stdc++.h>
using namespace std;

// Rank Heuristic
class DisjointSet{
private:
    vector<int> rank;
    vector<int> prnt;
public:
    DisjointSet(int n){
        rank.assign(n+1,0);
        prnt.resize(n+1);
        for(int i=0;i<=n;i++)prnt[i]=i;
    }
    int get(int x){
        if(x==prnt[x])return x;
        return prnt[x]=get(prnt[x]);
    }
    void merge(int x,int y){
        x=get(x),y=get(y);
        if(x==y)return;
        if(rank[x]>rank[y])swap(x,y);
        prnt[x]=y;  // y <- x
        if(rank[x]==rank[y])rank[y]++;
    }
};