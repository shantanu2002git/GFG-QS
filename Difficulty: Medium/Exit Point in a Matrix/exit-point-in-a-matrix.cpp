//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool validOut(int i, int j, int n, int m) {
        return (i < 0 || i >= n || j < 0 || j >= m);
    }

    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mst) {
        int i = 0, j = 0;
        char dir = 'R';  // Start direction is right
        
        while (!validOut(i, j, n, m)) {
            if (mst[i][j] == 1) {
                mst[i][j] = 0; // Turn off the switch
                if (dir == 'R') dir = 'D';
                else if (dir == 'D') dir = 'L';
                else if (dir == 'L') dir = 'U';
                else if (dir == 'U') dir = 'R';
            }
            
            if (dir == 'R') j++;
            else if (dir == 'D') i++;
            else if (dir == 'L') j--;
            else if (dir == 'U') i--;
        }
        
        if (dir == 'R') j--;
        else if (dir == 'D') i--;
        else if (dir == 'L') j++;
        else if (dir == 'U') i++;
        
        return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends