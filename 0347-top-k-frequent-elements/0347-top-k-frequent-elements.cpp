class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpf;
        for(auto it : nums){
            mpf[it]++;
        }
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        for(auto [val,fq] : mpf){
            pq.push({fq,val});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};