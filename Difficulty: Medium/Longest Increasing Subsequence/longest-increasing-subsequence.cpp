class Solution {
  public:
  int call(int idx, int prv, int n, vector<int>&arr, vector<vector<int>>&dp){
      if(idx==n){
          return 0;
      }
      if(dp[idx][prv+1]!=-1){
          return dp[idx][prv+1];
      }
      int notTake=call(idx+1,prv,n,arr,dp);
      if(prv==-1 || arr[prv]<arr[idx]){
          notTake=max(notTake, (1+call(idx+1,idx,n,arr,dp)));
      }
      return dp[idx][prv+1]=notTake;
  }
    int lis(vector<int>& arr) {
        int n=arr.size();
       
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return call(0, -1, n, arr, dp);
    }
};