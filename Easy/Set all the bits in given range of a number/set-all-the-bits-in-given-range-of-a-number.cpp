//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setAllRangeBits(int N , int L , int R) {
      
        int chain=1<<(R-L+1);
        chain=chain-1;
        chain=chain<<(L-1);
        
        N=N | chain;
        return N;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}
// } Driver Code Ends