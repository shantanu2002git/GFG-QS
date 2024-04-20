//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    class disjoint_set {
    public:
        vector<int> R;

        disjoint_set(int no) : R(no) {
            iota(R.begin(), R.end(), 0);
        }

        int find(int nod) {
            return R[nod] == nod ? nod : R[nod] = find(R[nod]);
        }

        bool join(int it1, int it2) {
            it1 = find(it1);
            it2 = find(it2);
            if (it1 == it2) {
                return false;
            }
            R[it1] = it2;
            return true;
        }
    };

    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        vector<vector<int>> isln(n, vector<int>(m, 0));
        vector<int> res;
        disjoint_set ddn(n * m);
        int cnt = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (auto& it : operators) {
            int x = it[0], y = it[1];
            if (isln[x][y] == 1) {
                res.push_back(cnt);
                continue;
            }
            cnt++;
            isln[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                int nx = dx[k] + x;
                int ny = dy[k] + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && isln[nx][ny] == 1 && ddn.join(x * m + y, nx * m + ny)) {
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends