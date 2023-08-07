//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int res=0,mx=0;
    int caldfs(int i, int j, int n, int m,vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]){
            grid[i][j]=0;
            
return 1+caldfs(i+1,j-1,n,m,grid)+caldfs(i+1,j+1,n,m,grid)+caldfs(i-1,j-1,n,m,grid)
+caldfs(i-1,j+1,n,m,grid)+caldfs(i+1,j,n,m,grid)+caldfs(i,j-1,n,m,grid)
+caldfs(i-1,j,n,m,grid)+caldfs(i,j+1,n,m,grid);

        }
        return 0;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    mx=max(caldfs(i,j,n,m,grid),mx);
                }
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends