//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int toggleBits(int N , int L , int R) {
         int chain=1<<(R-L+1);
        chain=chain-1;
        chain=chain<<(L-1);
        
        N=N ^ chain;
        return N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,l,r;
        
        cin>>n>>l>>r;

        Solution ob;
        cout << ob.toggleBits(n,l,r) << endl;
    }
    return 0;
}
// } Driver Code Ends