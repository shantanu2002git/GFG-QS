//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   bool isvalid(int x,int y,int n,int m){
        
        return (x>=0 and x<n and y>=0 and y<m);
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    v.push_back({i,j});                
                }
            }
        }
    
        vector<pair<int,int>> steps={{-1,0},{1,0},{0,1},{0,-1}};
        
        for(int i=0;i<v.size();i++)
        {
        
            int level=1;
                
            queue<pair<int,int>> q;
            vector<vector<int>> vis(n,vector<int>(m,0));
            
            q.push({v[i].first,v[i].second});
            vis[v[i].first][v[i].second]=1;    
            
            while(!q.empty()){
            
                int sz=q.size();
            
                for(int i=0;i<sz;i++)
                {
                    
                    int x=q.front().first;
                    int y=q.front().second;
                
                    q.pop();
                
                    for(auto it:steps){
                         int childx = x+it.first;
                         int childy = y+it.second;
                     
                        if((!isvalid(childx,childy,n,m)) or (vis[childx][childy]) )
                        continue;
                        
                        if(board[childx][childy]==word[level]){
                            vis[childx][childy]=1;
                            q.push({childx,childy});
                        }
                    }
                }
            level++;
            }
        
        
            if(level==word.size()+1)
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends