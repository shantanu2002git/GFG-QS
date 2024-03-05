//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int call(vector<int>& hi, int i, int k, int n, vector<vector<int>>& dp) {
        if (i >= n - 1) {
            return 0;
        }

        int& ret = dp[i][k];
        if (ret != -1) {
            return ret;
        }

        int mn = 1e9;
        for (int st = 1; st <= k; st++) {
            if (i + st < n) {
                mn = min(mn, abs(hi[i] - hi[i + st]) + call(hi, i + st, k, n, dp));
            }
        }
        return ret = mn;
    }

    int minimizeCost(vector<int>& hi, int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return call(hi, 0, k, n, dp);
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends