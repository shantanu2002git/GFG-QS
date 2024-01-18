//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
       vector<int>topo;
       vector<int>indg(v,0);
       for(int i=0; i<v; i++){
           for(auto it : adj[i]){
               indg[it]++;
           }
       }
       
       queue<int>q;
       for(int i=0; i<v; i++){
           if(indg[i]==0){
               q.push(i);
           }
       }
       
       while(!q.empty()){
           int fnt=q.front();
           q.pop();
           topo.push_back(fnt);
           for(auto it : adj[fnt]){
               indg[it]--;
               if(indg[it]==0){
                   q.push(it);
               }
           }
       }
       
       return (topo.size()!=v);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends