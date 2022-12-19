/*
    Author : Bhavya Kawatra
 Institute : MAIT
      Dept : CST
     Email : bhavyakawatra6@gmail.com
 CF handle : BhavyaKawatra13
*/
#include <bits/stdc++.h>
using namespace std;

/*
    x [a b a d a b a] d
    0 [1 2 3 4 5 6 7] 8 
dp[i]  1 2 1 4 1    
       l M   x   i r    
            mirror of y  -> r-y+l
*/

/*
even : 
    d[2*i] = 2 * d2[i] + 1
odd :
    d[2*i+1] = 2 * d1[i]

1. i is the index of the center letter of the current palindrome.
2. if size of palindrome centered at i is x, then dp[i] stores (x+1)/2;
*/
/*------------------------------------begin------------------------------------*/

vector<int> manacher_odd(string s){
    s="$"+s+"^";
    int n=s.size();
    int l=1,r=1;
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        int mirror=l+(r-i);
        dp[i]=max(0,min(dp[r-i],dp[mirror]));
        while(s[i+dp[i]]==s[i-dp[i]])dp[i]++;
        if(i+dp[i]>r){
            r=i+dp[i];l=i-dp[i];
        }
    }
    return vector<int>(dp.begin()+1,dp.end()-1);
}
vector<int> manacher(string s){
    string t;
    for(auto c:s){
        t+=string("#")+c;
    }
    auto res=manacher_odd(t+"#");
    return vector<int>(begin(res),end(res));
    // return vector<int>(begin(res)+1,end(res)-1);
}
void solve(){
    string s;
    cin>>s;
    vector<int> d=manacher(s);
    int n=s.size();
    vector<int> dp(n);
    if(n%2){ // odd
        for(int i=0;i<n;i++){
            dp[i]=d[2*i+1]-1;
            cout<<(dp[i])<<" ";
        }
    }else{
        for(int i=0;i<n;i++){
            dp[i]=d[2*i]-1;
            cout<<(dp[i])<<" ";
        }
    }
}
// EVEN : if i & i-1 are center, then length of longest palindrom with center as i, i-1 is given by dp[i];

/*-------------------------------------end-------------------------------------*/
signed main()
{
    // mahadev;
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}