#include <bits/stdc++.h>
using namespace std;

// Path Compressing 

class DisjointSet{
private:
    vector<int> prnt;
public:
    DisjointSet(int n){
        prnt.resize(n+1);
        for(int i=0;i<=n;i++)prnt[i]=i;
    }
    int get(int x){
        if(x==prnt[x]){
            return x;
        }
        return prnt[x]=get(prnt[x]);
    }
    void merge(int x,int y){
        x=get(x),y=get(y);
        prnt[x]=y;
    }
};