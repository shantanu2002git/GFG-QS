//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int maxIndexDiff(int a[], int n) 
    { 
       vector<int>min_lr(n),mxi_rl(n);
       min_lr[0]=a[0];
       for(int i=1; i<n; i++){
           min_lr[i]=min(a[i],min_lr[i-1]);
       }
       mxi_rl[n-1]=a[n-1];
       
       for(int j=n-2; j>=0; j--){
           mxi_rl[j]=max(a[j],mxi_rl[j+1]);
       }
       
       int i=0,j=0, res=-1e9;
       while(i<n && j<n){
           if(min_lr[i]<=mxi_rl[j]){
               res=max(res,(j-i));
               j++;
           }
           else{
               i++;
           }
       }
       return res;
    }
};




//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends