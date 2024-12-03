class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> ind(n, 0);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        int newnd = -1;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                if (newnd == -1) {
                    q.push(i);
                } else {
                    return -1;
                }
                newnd = i;
            }
        }

        while (!q.empty()) {
            int tp = q.front();
            q.pop();
            for (auto i : adj[tp]) {
                ind[i]--;
                if (ind[i] == 0) {
                    q.push(i);
                }
            }
        }
        return (q.size() == 0) ? newnd : -1;
    }
};