//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
      for(int i=0; i<V; i++){
          queue<int>q;
          vector<int>vis(V,0);
          q.push(i);
          while(!q.empty()){
              int ff=q.front();
              q.pop();
              if(vis[ff]==1){
                  return true;
              }
              vis[ff]=1;
              for(auto it : adj[ff]){
                  if(vis[it]==0){
                      q.push(it);
                  }
              }
          }
      }
      return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends