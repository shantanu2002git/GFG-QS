class Solution {
public:
    int negative_end(vector<int>& nums, int n) {
        int i = 0, j = n - 1, point = -1;
        while (i <= j) {
            int md = (i + j) / 2;
            if (nums[md] < 0) {  // Finding the last negative number
                point = md;
                i = md + 1; 
            } else {
                j = md - 1;
            }
        }
        return point;  // Returns index of last negative number
    }

    int posative_start(vector<int>& nums, int n) {
        int i = 0, j = n - 1, point = -1;
        while (i <= j) {
            int md = (i + j) / 2;
            if (nums[md] > 0) {  // Finding the first positive number
                point = md;
                j = md - 1; 
            } else {
                i = md + 1;
            }
        }
        return point;  // Returns index of first positive number
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = negative_end(nums, n);  // Last index of a negative number
        int pos = posative_start(nums, n);  // First index of a positive number

        int neg_count = (neg == -1) ? 0 : (neg + 1);  // Count of negative numbers
        int pos_count = (pos == -1) ? 0 : (n - pos);  // Count of positive numbers

        return max(neg_count, pos_count);
    }
};
