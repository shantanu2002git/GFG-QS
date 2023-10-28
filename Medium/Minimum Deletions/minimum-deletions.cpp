//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
  int l = 0;
  int caldp(string s, string rv, int idxS, int idxR, int n, vector<vector<int>> &dp)
  {
    if (idxS >= n || idxR >= n)
    {
      return 0;
    }
   if(dp[idxS][idxR]!=-1){
    return dp[idxS][idxR];
   }
    if (s[idxS] == rv[idxR])
    {
      return 1 + caldp(s, rv, idxS + 1, idxR + 1, n, dp);
      l++;
    }
    int l1 = caldp(s, rv, idxS + 1, idxR, n, dp);
    int l2 = caldp(s, rv, idxS, idxR + 1, n, dp);
    return dp[idxS][idxR]=max(l1, l2);
  }
  int minimumNumberOfDeletions(string S)
  {
    int n = S.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    string rv = S;
    reverse(rv.begin(), rv.end());
    //int k = caldp(S, rv, 0, 0, n, dp);
    //return (n - k);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(S[i-1]==rv[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                continue;
            }
            int l1=dp[i-1][j];
            int l2=dp[i][j-1];
            
            dp[i][j]=max(l1,l2);
        }
    }
    return n-dp[n][n];
   
  }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends