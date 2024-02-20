//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int TotalWays(const string& str) {
        const int md = 1e9 + 7;
        string ori = "GEEKS";
        int n = str.size();
        int m = ori.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
       
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        
      
        for (int r = m - 1; r >= 0; r--) {
            for (int i = n - 1; i >= 0; i--) {
                dp[i][r] = 0;
                if (str[i] == ori[r]) {
                    dp[i][r] = (dp[i + 1][r + 1] + dp[i + 1][r]) % md;
                } else {
                    dp[i][r] = dp[i + 1][r];
                }
            }
        }
        
        return dp[0][0];
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalWays(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends