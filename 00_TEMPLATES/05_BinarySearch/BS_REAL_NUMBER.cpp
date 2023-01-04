#include <bits/stdc++.h>
using namespace std;

#define sp(x) cout<<fixed;cout<<setprecision(x)

bool check(int mid){return true;}

int main(){
    double l=0,r=1e8;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }else r=mid;
    }
    sp(20);
    cout<<l<<endl;
    return 0;
}