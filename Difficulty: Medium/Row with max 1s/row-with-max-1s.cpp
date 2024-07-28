//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int res = -1;
        int maxCount = 0;
        int rows = arr.size();
        if (rows == 0) return res;
        int cols = arr[0].size();
        
        for (int rw = 0; rw < rows; ++rw) {
            int left = 0, right = cols;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (arr[rw][mid] == 1) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
           
            int count = cols - left;
            if (count > maxCount) {
                maxCount = count;
                res = rw;
            }
        }
        return res;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends