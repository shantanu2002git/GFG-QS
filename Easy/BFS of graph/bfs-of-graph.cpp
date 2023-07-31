//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
       vector<int>res;
       queue<int>q;
       vector<bool>trv(v,0);
       // there is undirected graph so give the direction don't  repeat the same path 
       q.push(0);
       trv[0]=1;
       while(!q.empty()){
          int n=q.size();
          for(int i=0; i<n; i++){
               int fnt=q.front();
               res.push_back(fnt);
           q.pop();
           for(auto it : adj[fnt]){
               if(trv[it]==0){
                  trv[it]=1;
                  q.push(it);
               }
           }
          }
       }
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends