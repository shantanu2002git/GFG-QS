class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
      queue<pair<int,int>>q;
      int n=grid.size(),m=grid[0].size();
      vector<vector<int>>dis(n+1, vector<int>(m+1, INT_MAX));
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             if(grid[i][j]){
                 q.push({i,j});
                 grid[i][j]=0;
             }else{
                 grid[i][j]=INT_MAX;
             }
         }
     }
     
     int dx[4]={1,-1,0,0};
     int dy[4]={0,0,-1,1};
     while(!q.empty()){
         auto [x,y]=q.front(); q.pop();
         for(int i=0;i<4; i++){
             int nwx=x+dx[i], nwy=y+dy[i];
             if(nwx>=0 && nwx<n && nwy>=0 && nwy<m && grid[nwx][nwy]==INT_MAX){
                 grid[nwx][nwy] = grid[x][y]+1;
                 q.push({nwx,nwy});
             }
         }
     }
     
     return grid;
        
    }
};