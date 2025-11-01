class Solution {
  public:
    int spanningTree(int v, vector<vector<int>>& edges) {
         vector<int>vis(v+1,0);
         vector<int>parent(v+1,-1);
         vector<vector<pair<int,int>>>adj(v+1);
         priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        
        for(auto it : edges){
           adj[it[0]].push_back({it[1], it[2]});
          adj[it[1]].push_back({it[0], it[2]});
      // ui, vi, wi
        }
        
        q.push({0, {0, -1}});// weight, node, parent
        int res=0;
        while(!q.empty()){
            auto it =q.top(); q.pop();
            int wei=it.first, nd=it.second.first, pan = it.second.second;
            if(vis[nd]) continue;
            vis[nd]=1;parent[nd]=pan;
            res=res+wei;
            for(auto t : adj[nd]){
                if(!vis[t.first]){
                    q.push({t.second, {t.first, nd}});
                    
                }
            }
        }
        return res;
    }
};