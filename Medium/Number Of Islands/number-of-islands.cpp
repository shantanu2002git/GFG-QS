//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void DFS(vector<vector<int>> &adj,int row,int col,vector<vector<int>> &vis)
    {
        int m = adj.size(),n = adj[0].size();
        vis[row][col] = 1;
        int dir[5] = {-1,0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+dir[i],ncol=col+dir[i+1];
            if(nrow<0 or ncol<0 or nrow>=m or ncol>=n or vis[nrow][ncol]) continue;
            if(adj[nrow][ncol]==1) DFS(adj,nrow,ncol,vis);
        }
    }
    
    int NoOfIslands(vector<vector<int>> &adj)
    {
        int m = adj.size(),n = adj[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and adj[i][j]==1)
                {
                    DFS(adj,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        vector<vector<int>> adj(n,vector<int> (m,0));
        vector<int> res;
        for(auto i : operators)
        {
            int u=i[0],v=i[1];
            adj[u][v] = 1;
            int count = NoOfIslands(adj);
            res.push_back(count);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends