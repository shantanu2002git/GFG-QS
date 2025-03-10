class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size(), i = 0, j = 0, res = 0, zero = 0;
        while (i < n) {
            mp[nums[i]]++;
            if(nums[i]==0){
                zero++;
            }
            while (zero > k) {
                if (nums[j] == 0) {
                    zero--;
                }
                j++;
            }

            cout << i << " " << j <<" "<< (i - j + 1) << endl;
            res = max(res, (i - j + 1));
            i++;
        }
        return res;
    }
};