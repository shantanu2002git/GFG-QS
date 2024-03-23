//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++


class Solution {
public:
    int call(int n, const string& s, unordered_map<string, int>& dp) {
        if (s.size() == n) {
            return 1;
        } else if (s.size() > n) {
            return 0;
        }

        if (dp.find(s) != dp.end()) {
            return dp[s];
        }

        int count = 0;

        if (s.empty() || s.back() != '1') {
            count += call(n, s + '1', dp);
        }
        count += call(n, s + '0', dp);

        dp[s] = count;

        return count;
    }

    long countStrings(int n) {
        
        string s = "";
        unordered_map<string, int> dp; 
       /* return call(n, s, dp); */
        int m = 1e9 +7;
        ll a =2;
        ll b =3;
        for(int i=2;i<=n;i++){
            ll temp = (a+b)%m;
            a = b;
            b = temp;
        }
        return a;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends