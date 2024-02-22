//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/


class Solution
{
    public:
    int mod=1e9+7;
    int cal(string s, string t , int i, int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int tt=0,nn=0;
        if(s[i]==t[j]){
            tt=cal(s,t,i-1,j-1,dp)+cal(s,t,i-1,j,dp);
        }else{
            nn=cal(s,t,i-1,j,dp);
        }
        return dp[i][j]=(tt+nn)%mod;
    }
    
    
    int subsequenceCount(string s, string t)
    {
        
      int n=s.size(), m=t.size();
       vector<vector<int>>dp(n,(vector<int>(m+1,-1)));
       return cal(s,t,n-1,m-1,dp);
      
      
      /*

     int mod=1e9+7,n=S.size(), m=T.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
           if(S[i-1]==T[j-1]) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        else dp[i][j]=dp[i-1][j]%mod;
        }
        }
        return dp[n][m];
        
        */
        
        /*
        int mod=1e9+7;
        int n=S.size(), m=T.size();
        vector<int>prev(n+1,0),cur(m+1,0);
        prev[0]=cur[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            if(S[i-1]==T[j-1]) cur[j]=(prev[j-1]+prev[j])%mod;
        else cur[j]=prev[j]%mod;
        }
         prev=cur;
        }
       return prev[m];
       */
       
       
    }
};
 



//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends