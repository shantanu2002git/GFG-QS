//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find the minimum number of platforms required
    // at the railway station such that no train waits.
    static int helper(int i, int j, int arr[], int dep[], int n, vector<vector<int>>& dp) {
        if (i == n || j == n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int platforms = 1;
        if (arr[i] <= dep[j]) {
            platforms = max(platforms, 1 + helper(i + 1, j, arr, dep, n, dp));
        } else {
            platforms = -1 + helper(i, j + 1, arr, dep, n, dp);
        }
        return dp[i][j] = platforms;
    }

    static int findPlatform(int arr[], int dep[], int n) {
        // Initializing a 2D vector with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Sorting the arrival and departure arrays
        sort(arr, arr + n);
        sort(dep, dep + n);

        return helper(0, 0, arr, dep, n, dp);
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends