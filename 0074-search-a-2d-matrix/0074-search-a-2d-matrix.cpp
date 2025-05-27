class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size(), m=mat[0].size();
        int rw=0, cl=m-1;

        while(rw<n && cl>=0){
            int ele=mat[rw][cl];
            if(ele==t) return true;

            if(ele>t){
cl--;
            }else{
                rw++;
            }
        }
        return 0;

    }
};