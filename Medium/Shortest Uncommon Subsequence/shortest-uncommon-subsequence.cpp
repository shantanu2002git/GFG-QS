//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    int findShortest(vector<vector<int>> &dp, string &S, string &T, int n, int m, int i, int j) {
        // If we reach the end of S, it means we were not able to find a subsequence which was not common
        if (i >= n) {
            return 1e9; // Return a large value as a placeholder
        }
        // If we reach the end of T but not of S, then any remaining characters in S will be uncommon
        if (j >= m) {
            return 1; // We can add any remaining characters of S to make an uncommon subsequence
        }
     
       if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Find the position of the character S[i] in T starting from index j
        int k;
        for (k = j; k < m; k++) {
            if (S[i] == T[k]) {
                break; // Found a matching character
            }
        }
        
        // If we didn't find the character S[i] in T, then adding it to the subsequence will make it uncommon
        if (k == m) {
            return 1; // Adding S[i] to the subsequence makes it uncommon
        }
        
        // Two options:
        // 1. Do not include S[i] in the subsequence, move to the next character in S
        // 2. Include S[i] in the subsequence, move to the next character in both S and T
        return dp[i][j] = min(findShortest(dp, S, T, n, m, i + 1, j), 1 + findShortest(dp, S, T, n, m, i + 1, k + 1));
    }
  
    // Main function to find the shortest uncommon subsequence
    int shortestUnSub(string S, string T) {
        int n = S.size();
        int m = T.size();
      
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        int ans = findShortest(dp, S, T, n, m, 0, 0);
        // If the result is greater than or equal to 501, return -1 as no uncommon subsequence found
        return ans >= 1e9 ? -1 : ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends