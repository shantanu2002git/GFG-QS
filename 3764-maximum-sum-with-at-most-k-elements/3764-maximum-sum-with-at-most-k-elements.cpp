class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int>pq;
int rw=grid.size();        
        for(int i=0; i<rw; i++){
            // big->small
            sort(grid[i].begin(),grid[i].end(), greater<int>());
            int nwl=min(limits[i],k);
            for(int j=0; j<nwl; j++){
                // if(j<grid[i])
                pq.push(grid[i][j]);
            }
}
        
  long long res=0;      
        while(k>0 && !pq.empty()){
res=res+pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};