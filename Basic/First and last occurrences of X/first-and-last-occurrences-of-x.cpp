//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
      int lef=-1,rig=-1;
      int in=1,nc=1;
      for(int i=0; i<n; i++){
          if(x==arr[i] && in){
              lef=i; in=0;
          }
          if(x==arr[n-i-1] && nc){
              rig=n-i-1;
              nc=0;
          }
      }
      vector<int>res;
      if(lef>-1 && rig>-1){
      res.push_back(lef);
      res.push_back(rig);
      
      return res;
      }
      return {-1};
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends