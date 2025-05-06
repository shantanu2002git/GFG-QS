class Solution {
public:
    int res = 0;
    void call(int st, int en, vector<vector<int>>& grid, int n, int m) {
        // if () {
        // }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({st, en});
        grid[st][en] = 0;
        int cnt=1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            for (int i = 0; i < 4; i++) {
                int nwx = dx[i] + x, nwy = dy[i] + y;
                if (nwx >= 0 && nwx < n && nwy >= 0 && nwy < m &&
                    grid[nwx][nwy]) {
                    q.push({nwx, nwy});
                      grid[nwx][nwy]=0;
                    cnt++;
                }
            }
        }
        res=max(res, cnt);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

    
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    call(i, j, grid, n, m);
                }
            }
        }

        return res;
    }
};