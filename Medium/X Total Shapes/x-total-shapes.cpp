//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    void dfs(vector<vector<char>> &grid,int i,int j,int row, int col){
        if(i<0||j<0||i>(row-1)||j>(col-1)||grid[i][j]!='X')
        return;
        
        if(grid[i][j]=='X')
        {
            grid[i][j]='O';
            
            dfs(grid,i+1,j,row,col);
            dfs(grid,i,j+1,row,col);
            dfs(grid,i-1,j,row,col);
            dfs(grid,i,j-1,row,col);
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X')
                count++;
                dfs(grid,i,j,n,m);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends