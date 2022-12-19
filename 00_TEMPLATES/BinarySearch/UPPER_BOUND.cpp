#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    int q;cin>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(q--){
        // -----UB code start here----
        int l=-1,r=n;
        int value;cin>>value;
        while(r-l>1){
            int mid=(l+r)>>1;
            if(a[mid]<=value){
                l=mid;
            }else r=mid;
        }
        cout<<r<<endl;
        // -----UB code ends here----
    }
    return 0;
}
// 5 6 6 7
// ub of 6