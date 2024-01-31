//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void call(int nd, vector<vector<int>>& adj, vector<int>& vis) {
        vis[nd] = 1;
        for (int i = 0; i < adj[nd].size(); i++) {
            if (adj[nd][i] == 1 && !vis[i]) {
                call(i, adj, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>>& adj, int V) {
        vector<int> vis(V, 0);
        int c = 0, n = V;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                call(i, adj, vis);
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