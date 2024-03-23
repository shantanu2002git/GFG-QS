//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    long long dp[1001];
    
    long long solve(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        long long mx = 0;
        for (int i = 1; i < n; i++) {
            mx = max(mx, max(1LL * i * (n - i), 1LL * i * solve(n - i)));
        }
        return dp[n] = mx;
    }
    
    long long maxProduct(int n) {
        // Initialize dp array with -1
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends