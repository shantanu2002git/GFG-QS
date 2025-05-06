class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        // track all rotting orange ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // rottn orange
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int time = 0;
        while (!q.empty()) {

            int nq = q.size();
            bool complet = false;
            while (nq--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                for (int i = 0; i < 4; i++) {
                    int nwx = dx[i] + x, nwy = dy[i] + y;
                    if (nwx >= 0 && nwx < n && nwy >= 0 && nwy < m &&
                        grid[nwx][nwy] == 1) {
                        q.push({nwx, nwy});
                        grid[nwx][nwy] = 2;
                        complet = true;
                        fresh--;
                    }
                }
               
            }
             if (complet) {
                    time++;
                }
        }

        return (fresh == 0) ? time : -1;
    }
};