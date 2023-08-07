//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void call(int i, vector<int>&vis,vector<vector<int>>&adj, int v){
        vis[i]=1;
        for(int j=0; j<v; j++){
            if(!vis[j] && adj[i][j]==1){
                call(j,vis,adj,v);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
      vector<int>vis(v,0);
      int c=0;
      for(int i=0; i<v; i++){
          if(!vis[i]){
              call(i,vis,adj,v);
              c++;
          }
      }
      return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends