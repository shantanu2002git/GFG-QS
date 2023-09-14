//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

	public:
	int mod=1e9+7;
	int cal(int arr[], int idx, int sum, vector<vector<int>>&dp){
	    if(idx==-1){
	        return sum==0;
	    }
	    if(dp[idx][sum]!=-1){
	        return dp[idx][sum];
	    }
	    
	    int pick=0,notp=0;
	    notp = cal(arr,idx-1,sum,dp)%mod;
	     if(sum>=arr[idx]){
	         pick=cal(arr,idx-1,sum-arr[idx],dp)%mod;
	     }
	     return dp[idx][sum]=(notp+pick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n+1,(vector<int>(sum+1,-1)));
        
        return cal(arr,n-1,sum,dp)%mod;
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends