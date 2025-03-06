class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>track((n*n)+1,-1);
        vector<int>res;
        for(auto it : grid){
            for(auto i : it){
                if(track[i]==-1)
                {
                    track[i]=i;
                }else{
                    res.push_back(i);
                }
            }
        }
        for(int i=1; i<=n*n; i++){
            int it=track[i];
            if(it==-1){
                res.push_back(i);
            }
        }
        return res;
    }
};