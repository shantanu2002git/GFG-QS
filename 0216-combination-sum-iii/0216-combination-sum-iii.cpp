class Solution {
public:
    vector<vector<int>> res;
    void call(vector<int>& in, int k,int idx, int s) {
        if (s == 0 && k == 0) {
            res.push_back(in);
            return;
        }
        for (int i = idx; i <= 9; i++) {
            if (i <= s) {
                in.push_back(i);
                call(in, k - 1, i+1, s - i);
                in.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> in;
        call(in, k,1, target);
        return res;
    }
};