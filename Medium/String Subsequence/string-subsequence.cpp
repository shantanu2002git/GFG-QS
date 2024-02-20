//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
int md=1e9+7;
    int call(int i, int n, string s1, int j, int m, string s2) {
        if (j == m) {
            return 1;
        }
        int tt = 0; // Initialize tt
        for (int it = i; it < n; it++) {
            if (s1[it] == s2[j]) {
                tt += (call(it + 1, n, s1, j + 1, m, s2))%md; // Increment tt instead of assigning
            }
        }
        return tt%md;
    }
    
    int countWays(string s1, string s2) { // Corrected variable names
        int n = s1.size(); // Corrected variable name
        int m = s2.size(); // Corrected variable name
        return call(0, n, s1, 0, m, s2);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends