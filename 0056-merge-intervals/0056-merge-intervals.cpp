class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        vector<vector<int>> res;
        if (inv.empty()) return res;

        sort(inv.begin(), inv.end());
        vector<int> in = inv[0];  

        for (auto it : inv) {
            if (it[0] <= in[1]) {  
                in[1] = max(in[1], it[1]);
            } else {  
                res.push_back(in);
                in = it;
            }
        }

        res.push_back(in); 
        return res;
    }
};
