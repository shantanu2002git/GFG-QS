//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
#define mod 1000000007
class Solution
{
    public:
    
    ll help(ll n,vector<int>&dp)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
       
       if(dp[n]!=-1){
           return dp[n];
       }
        ll a=help(n-1,dp);
        ll b=help(n-2,dp);
        ll c=help(n-3,dp);
        
        return dp[n]=(((a+b)%mod)+c)%mod;
    }
    long long countWays(int n)
    {
        vector<int>dp(n+1, -1);
        return help(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends