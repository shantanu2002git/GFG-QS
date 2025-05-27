class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n;
        if(nums[n-1]<target){
            return n;
        }

        while(left<right){
            int md=(left+right)/2;
            if(nums[md]==target) return md;

            if(nums[md]>target){
                right=md;
            }else{
                left=md+1;
            }
        }
        return right;
    }
};