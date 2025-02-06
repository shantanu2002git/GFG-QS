class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ld = 0, li = 0, res1 = 0, res2 = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                li++;
                res1 = max(res1, li);
            } else {
                li = 0;
            }

            if (nums[i] < nums[i - 1]) {
                ld++;
                res2 = max(res2, ld);
            } else {
                ld = 0;
            }
        }
        return max(res1, res2)+1;
    }
};