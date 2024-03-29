//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int caldp(int idx1, int idx2, string s1, string s2,  vector<vector<int>>&dp){
        if(idx1==0 ||idx2==0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(s1[idx1-1]==s2[idx2-1]){
          return   dp[idx1][idx2]=1+caldp(idx1-1,idx2-1,s1,s2,dp);
        }
        return dp[idx1][idx2]=max(caldp(idx1-1,idx2,s1,s2,dp),caldp(idx1,idx2-1,s1,s2,dp));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // return caldp(n,m,s1,s2,dp);
       for(int i=0; i<=n; i++) dp[i][0]=0;
       for(int j=0; j<=m; j++) dp[0][j]=0;
       
       for(int i=1; i<=n; i++){
           for(int j=1; j<=m; j++){
               if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
               else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends