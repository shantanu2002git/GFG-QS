//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
       unordered_map<int,int>mp;
       int s=0,mx=-0;
       mp.insert({s,-1});
       for(int i=0; i<n; i++){
           s=s+arr[i];
          if(mp.find(s)!=mp.end()){
              int df=(i-mp[s]);
              mx=max(mx,df);
          }
          
          mp.insert({s,i});
       }
       return mx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends