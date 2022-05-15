#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMin(int arr[], int n){
        int l=0,h=n-1;
        if(arr[0]<=arr[n-1])return arr[0];//equal bcz agr ek elemnt hua too
        while(l<h){
            int mid=(l+h)/2;
            // cout<<mid<<" "<<arr[l]<<" "<<arr[mid]<<endl;
            if(arr[l] < arr[h]){
                return arr[l];
            }
            if(arr[mid-1]>arr[mid]&&mid-1>=0)return arr[mid];//checking mid
            if(arr[mid-2]>arr[mid-1]&&mid-2>=0)return arr[mid-1];//checking mid-1
            if(arr[mid]>arr[mid+1]&&mid>=0)return arr[mid+1];//checking mid+1
            if(arr[l]>arr[mid]){
                // cout<<"upr OK";
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return arr[l];
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends