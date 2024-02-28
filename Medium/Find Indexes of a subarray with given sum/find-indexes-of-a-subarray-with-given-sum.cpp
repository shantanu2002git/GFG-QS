//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
#define pb push_back

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
     /*
        for(int i=0;i<n;i++)
        {
            long long  ts=0;
            for(int j=i;j<n;j++)
            {
                ts+=arr[j];
                if(ts==s)
                {
                    return {i+1,j+1};
                }
            }
        }
        return {-1};
        */
        
        int i=0,j=0;
        ll ts=0;
        while(i<n){
            ts=ts+arr[i];
            
                while(ts>s && j<i){
                ts=ts-arr[j];
                j++;
                }
                if(s==ts){
                return {j+1,i+1};
            }
            
            i++;
        }
        return {-1};
       
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends