class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        sort(inv.begin(), inv.end());
        vector<int> in = inv[0];
        int res = 0;
        for (auto it : inv) {
            if (it[0] <= in[0]) {
                res++;
                in[1] = max(it[1], in[1]);
            } else {
                in = it;
            }
        }
        return res-1;
    }
};