class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector <int> ans ;

        for (int i {0} ; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
         for (int i {0} ; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;

    }
};
/*
https://drive.google.com/file/d/11DtYi_wqEO0B87ikthDd9cjiMrOn7Pon/view?usp=sharing
*/