class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mpn;
        for (auto it : nums) {
            mpn[it]++;
        }
        int res = 0, mx = 0, prev=INT_MIN, cnt=0;
        for (auto it : mpn){
            if(it.first==prev+1){
                cnt++;
            }else{
                cnt=1;
            }
            res=max(res,cnt);
            prev=it.first;
        }
        return res;
    }

};