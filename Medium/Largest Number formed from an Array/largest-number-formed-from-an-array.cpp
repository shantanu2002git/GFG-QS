//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    static bool comp(const std::string &s1, const std::string &s2) {
        return s1 + s2 > s2 + s1;
    }

    std::string printLargest(int n, vector<std::string> &arr) {
        sort(arr.begin(), arr.end(), comp);
        string res = "";
        for (const auto &it : arr) {
            res += it;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends