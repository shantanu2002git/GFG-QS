class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        vector<bool> res;
        int n = l.size();
        for (int i = 0; i < n; i++) {
            int st = l[i], en = r[i];
            //  if (en - st < 1) {
            //     res.push_back(true);
            //     continue;
            // }
            vector<int>sub(nums.begin()+st, nums.begin()+en+1);
            sort(sub.begin() , sub.end());

            int diff = sub[1] - sub[0];
            bool isArrthic=true;
            for (int j = 2; j <sub.size(); j++) {
                if ((sub[j] - sub[j - 1]) != diff) {
                    isArrthic=false;
                    break;
                }
            }
            res.push_back(isArrthic);
        }
        return res;
    }
};