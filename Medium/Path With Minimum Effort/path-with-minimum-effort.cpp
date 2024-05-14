//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  int n,m;
   int MinimumEffort(int rw, int cl,vector<vector<int>>& heights) {
  
        // create a priority queue to implement dijkstra algo.
        // we store in form {diff, {row,col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        
        int m = rw;
        int n = cl;
        
        // create a 2d dist vector where we store the absolute diff
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        // push source cordinate in pq with differece 0
        pq.push({0, {0, 0}});
        
        // delta row and delta col to move in 4 direction
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // implimenting dijkstra algo
        while(!pq.empty()) {
            // top elment in pq means elemnt having minimum diff in pq
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            // check, if we reach to the destination with minmum effort then return ans
            if(r == m-1 and c == n-1)
                return diff;
                
            // iterate in all possible 4 direction
            for(int i=0; i<4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n) {
                    int newEffort = max(abs(heights[nrow][ncol]-heights[r][c]), diff);
                    // if we newEffort is minimum then the current effort
                    // then we update the dist vector and push {newEffor, {nrow, ncol}} in pq
                    if(newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0;
    }
};


/*
1 2 2
3 8 2
5 3 5
*/


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends