//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        for(int i=0; i<v; i++){
        vector<bool>vist(v,true);
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int fnt=q.front();
                q.pop();
                if(vist[fnt]==false){
                    return true;
                }
                vist[fnt]=false;
                for(auto it : adj[fnt]){
                    if(vist[it]==true){
                        q.push(it);
                    }
                }
                
            }
        }
        return false;
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