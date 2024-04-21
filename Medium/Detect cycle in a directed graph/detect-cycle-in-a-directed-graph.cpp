//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        int n=v;
        vector<int>in(n,0);
       for(int i=0; i<n; i++){
           for(int j : adj[i])
           {
               in[j]++;
           }
       }
       
       queue<int>q;
       for(int i=0; i<n; i++){
           if(in[i]==0){
               q.push(i);
           }
       }
       
       while(!q.empty()){
           int nx=q.size();
          while(nx--){
               int f=q.front();
               q.pop();
               
               for(auto t : adj[f]){
                   in[t]--;
                   if(in[t]==0){
                       q.push(t);
                  }
               }
          }
       }
       for(int i=0; i<n; i++){
           if(in[i]>0){
               return 1;
           }
       }
       return 0;
 
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