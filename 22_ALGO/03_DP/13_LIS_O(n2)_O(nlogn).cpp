/*-----------------begin---------------*/
//dp approach!! O(n2)
int LIS(vector<int> arr)
{
    int n=arr.size();
    int dp[n]={0};
    dp[0]=1;
    ffor(i,1,n){
        bfor(j,i,0){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        dp[i]=max(1,dp[i]);
    }
    int ans=1;
    ffor(i,0,n){
        ans=max(ans,dp[i]);
    }
    return ans;
}
//returns vector of lonest inc. subsequence! O(n2)
vi LIS2(vector<int> arr)
{
    int n=arr.size();
    int dp[n]={0};
    vector<int>p(n,-1);//parent array to print the LIS
    vi subsequence;
    dp[0]=1;
    ffor(i,1,n){
        bfor(j,i,0){
            if(arr[i]>arr[j]){
                int f=dp[i];
                dp[i]=max(dp[j]+1,dp[i]);
                if(dp[i]!=f)p[i]=j;
            }
        }
        dp[i]=max(1,dp[i]);
    }
    int ans=1,ind=1;
    ffor(i,0,n){
        if(dp[i]>ans){ans=dp[i];ind=i;}
    }
    while(p[ind]!=-1){
        subsequence.pb(arr[ind]);
        ind=p[ind];
    }
    return subsequence;
}
//dp O(n2) diff. approach!
int LIS3(vi arr){
    int n=arr.size();
    vi dp(n+1,im);
    dp[0]=-im;
    //dp[j] tells ki 'j' length ki jo inc. seq. bni hai;
    //us sequence ka last elemnt is given by dp[j]
    ffor(i,0,n){
        ffor(j,1,n+1){
            if(arr[i]<dp[j]&&arr[i]>dp[j-1]){
                dp[j]=arr[i];
            }
        }
    }
    int ans=0;
    ffor(i,1,n+1)if(dp[i]<im)ans=i;
    return ans;
}
//O(nlogn)
int LIS4(vi arr){
    int n=arr.size();
    vi dp(n+1,im);
    dp[0]=-im;
    //dp[j] tells ki 'j' length ki jo inc. seq. bni hai;
    //us sequence ka last element is given by dp[j]
    ffor(i,0,n){
        auto x=ub(dp.begin(),dp.end(),arr[i]);
        int j=x-dp.begin();//j is the index value that has to be updated!
        //j is found here in log n tym by upperbound func. which internally uses BINARY SEARCH!
        //hence tym comp. of total func. will be now nlogn!
        if(arr[i]>=dp[j-1]&&arr[i]<dp[j]){//= if duplicates are allowed!
            dp[j]=arr[i];
        }
    }
    int ans=0;
    ffor(i,1,n+1)if(dp[i]<im)ans=i;
    return ans;
}

void solve()
{
    in2(n,m);
    vi a(n),b(m);
    ffor(i,0,n)cin>>a[i];
    ffor(i,0,m)cin>>b[i];
    cout<<LIS4(a)+LIS4(b)<<endl;
}
/*-----------------end---------------*/
