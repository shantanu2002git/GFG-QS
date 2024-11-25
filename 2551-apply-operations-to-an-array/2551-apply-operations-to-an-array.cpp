class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int i = 0, j = 0;
        while (i < n) {
            if (nums[i] == 0) {
                i++;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return nums;
    }
};
