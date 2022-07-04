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
#define sz size()
#define mahadev ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vfor(v) for (auto itr =v.begin() ; itr!=v.end(); itr++)
#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(v) v.begin(),v.end()
#define pn(p) cout<<p<<endl

/*------------------------------------begin------------------------------------*/
string LCS(string s,string s2){
    int sk=s.sz;
    int sk2=s2.sz;
    vvi dp(sk+1,vi(sk2+1,0));
    // dp[i][j] -> longest common subseqence when taking string1 length till i
    // and string2 length till j
    ffor(i,1,sk+1){
        ffor(j,1,sk2+1){
            if(s[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=sk,j=sk2;
    string ans;
    while(i>0&&j>0){
        if(dp[i][j]==dp[i][j-1]){j--;continue;}
        if(dp[i][j]==dp[i-1][j]){i--;continue;}
        ans.pb(s2[j-1]);
        i--;j--;
    }
    reverse(all(ans));
    return ans;//contains longest common subsequence!
    // dp[sk][sk2] or ans.size() -> length of longest common subsequence
}

void solve()
{
    string s;cin>>s;
    string s2;cin>>s2;
    string lcs=LCS(s,s2);
    pn(lcs.sz);// length of longest common subsequence
}

/*-------------------------------------end-------------------------------------*/
signed main()
{
    mahadev;

    solve();
    return 0;
}