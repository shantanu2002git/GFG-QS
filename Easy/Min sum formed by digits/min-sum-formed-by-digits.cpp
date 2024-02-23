//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
       
        sort(arr,arr+n);
        long long s1=0,s2=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                s1=s1*10+arr[i];
            }else{
                s2=s2*10+arr[i];
            }
        }
        // cout<<s1<<" "<<s2;
        return abs(s1+s2);
    }
    /*
2 3 4 5 6 8
246 -358

0 3 4 5 7
047 -35
    */
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends