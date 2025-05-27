class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int rws=mat.size(),col=mat[0].size();
        int rw=0 ,cl=col-1;
        while(rw<rws && cl>=0){
if(mat[rw][cl]==t) return 1;
if(mat[rw][cl]<t){
    rw++;
}else{
    cl--;
}
        }
        return 0;
    }
};