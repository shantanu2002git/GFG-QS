class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mps;
        for(int i=0; i<nums.size(); i++){
            if(mps.find(target-nums[i])!=mps.end() && i!=mps[target-nums[i]]){
                return {i, mps[target-nums[i]]};
            }
            mps[nums[i]]=i;

        }

      
        return {};
    }
};