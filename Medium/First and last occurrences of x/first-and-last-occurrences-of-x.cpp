//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
       int i=0,j=n-1;
       vector<int>vc(2,-1);
     while(i<=j){
         if(arr[i]==x && arr[j]==x){
             vc[0]=(i);
             vc[1]=(j);
             break;
         }
         if(arr[i]!=x) i++;
         if(arr[j]!=x) j--;
     }
     return vc;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends