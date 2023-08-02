//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(!A[0][0]) return -1;
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int ans = 1e9;
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int c = q.front().second;
            q.pop();
            if(i==X && j==Y) {
                ans =c;
                continue;
            }
            else {
                for(int k=0;k<4;k++) {
                    int ni = i + delrow[k];
                    int nj = j + delcol[k];
                    if(ni>=0 && ni<N && nj>=0 && nj<M && !vis[ni][nj] && A[ni][nj]) {
                        //vis[ni][nj]=1;
                        q.push({{ni,nj},c+1});
                        A[ni][nj]=0;
                    }
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends