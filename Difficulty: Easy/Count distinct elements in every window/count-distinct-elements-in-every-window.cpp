//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
       int  i=0,j=0;
       map<int,int>mp;
       vector<int>res;
       
       while(i<n){
           mp[arr[i]]++;
           if(i-j+1==k){
               res.push_back(mp.size());
          
               mp[arr[j]]--;
               if(mp[arr[j]]==0){
                   mp.erase(arr[j]);
               }
               j++;
           }
           i++;
       }
       return res;
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends