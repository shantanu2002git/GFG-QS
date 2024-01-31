//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  int call(int arr[], int n){
     int mx=0,curr=0,c=0;
     for(int i=0; i<n-1; i++){
         mx=max(mx,arr[i]+i);
         if(i==curr){
             c++;
             curr=mx;
         }
     }
     
     if(curr>=n-1){
         return c;
     }
     return -1;
  }
    int minJumps(int arr[], int n){
       return call(arr,n);
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