class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT16_MAX));
        queue<pair<int, int>> q;
      
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    dis[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int rw = it.first, cl = it.second;
            for (int i = 0; i < 4; i++)
            {
                int nrw = dx[i] + rw, ncl = dy[i] + cl;
                if (nrw >= 0 && nrw < n && ncl >= 0 && ncl < m)
                {
                    if ((dis[nrw][ncl] > dis[rw][cl] + 1))
                    {
                        dis[nrw][ncl] = dis[rw][cl]   + 1;
                       q.push({nrw,ncl});
                    }
                }
            }
        }
        return dis;
    }
};
