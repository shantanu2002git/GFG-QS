//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	   vector<bool>trv(v,0);
	   queue<int>q;
	   int lvl=0;
	   q.push(0);
	   trv[0]=1;
	   while(!q.empty()){
	       int n=q.size();
	       while(n--){
	           int fnt=q.front();
	           q.pop();
	           if(fnt==x){
	               return lvl;
	               break;
	           }
	           for(auto it : adj[fnt]){
	               if(trv[it]==0){
	                   q.push(it);
	                   trv[it]=1;
	               }
	           }
	           
	       }
	       lvl++;
	   }
	   return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends