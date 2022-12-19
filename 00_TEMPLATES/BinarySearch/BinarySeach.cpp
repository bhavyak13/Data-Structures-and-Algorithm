#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;cin>>n;
    int q;cin>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(q--){
        // -----BS code start here----
        int l=0,r=n-1;
        int value;cin>>value;
        bool ok=false;
        while(r>=l){
            int mid=(l+r)>>1;
            if(a[mid]==value){
                ok=true;
                break;
            }else if(a[mid]<value){
                l=mid+1;
            }else r=mid-1;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // -----BS code ends here----
    }
    return 0;
}
// 5 5 6 6 7
// BS -> 6