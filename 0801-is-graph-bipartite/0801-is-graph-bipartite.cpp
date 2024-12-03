class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
              if(color[i]){
                    continue;
                }
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int tp = q.front();
                q.pop();
              
                for (auto it : graph[tp]) {
                    if (color[it] == 0) {
                        color[it] = -color[tp];
                        q.push(it);
                    } else if (color[it] == color[tp]) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};