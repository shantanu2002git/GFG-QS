//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
int call(vector<int> &arr,vector<int>&dp, int n)
  {
    if (n == 0)
    {
      return arr[0];
    }
    if (n < 0)
    {
      return 0;
    }
if(dp[n]!=-1){
    return dp[n];
}
    int include = arr[n] + call(arr, dp, n - 2);
    int exclude = call(arr, dp, n - 1);
    return dp[n]=max(include, exclude);
  }
	int findMaxSum(vector<int>&arr, int n) {
	
	    vector<int>dp(n+1,-1);
	   return call(arr,dp,n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends