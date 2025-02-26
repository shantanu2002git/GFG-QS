class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN, sum = 0;
        for (auto it : nums) {
            sum = sum + it;
         
                res = max(sum, res);
            if (sum < 0 ) {
              
                sum = 0;
            }
        }
        return res;
    }
};