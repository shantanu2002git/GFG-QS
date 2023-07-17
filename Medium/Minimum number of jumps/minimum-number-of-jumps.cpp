//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

/*
class Solution{
  public:
  int cal(int idx, int n, int arr[], vector<int>&dp){
      if(idx==n){
          return 0;
      }
      if(dp[idx]!=-1){
          return dp[idx];
      }
      int jmp=1e9;
      for(int i=arr[idx]; i>=1; i--){
          if(idx+i<=n){
              jmp=min(jmp,1+cal(idx+i,n,arr,dp));
          }
      }
      return dp[idx]=jmp;
  }
    int minJumps(int arr[], int n){
        // Your code here
        vector<int>dp(n,-1);
        return cal(0,n-1,arr,dp)==1e9 ?-1:cal(0,n-1,arr,dp);// T.c O(n) S.C O(n*n)
    }
};

*/
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int furthest=0; 
        int end=0;
        int jump=0;
       for(int ind=0;ind<n-1;ind++)
        {
            furthest=max(furthest,arr[ind]+ind);
            if(end==ind)
            {
                jump++;
                if(end==furthest){
                return -1;
                }
                end=furthest;
            }
        }
        return jump;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends