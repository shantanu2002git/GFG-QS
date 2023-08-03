//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
       vector<int>cost(n,1e9);
			 unordered_map<int,vector<pair<int,int>>>adj;
			 for(auto it : edges){
				adj[it[0]].push_back({it[1],it[2]});
			 }
			 queue<pair<int,int>>q;
			 q.push({0,0});
			 cost[0]=0;
			 
			 while(!q.empty()){
				auto fnt=q.front();
				q.pop();
				int u=fnt.first,dis1=fnt.second;

				for(auto it  : adj[u]){
					int dis2=it.second,v=it.first;

           if(cost[v]>dis1+dis2){
                  cost[v]=dis1+dis2;
									q.push({v,dis1+dis2});
					 }
				}

			 }
			 vector<int>res(n,-1);
for(int i=0; i<cost.size(); i++){
	if(cost[i]==1e9){
	    res[i]=-1;
	}else{
	    res[i]=cost[i];
	}
}
return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends