class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<tuple<int,int,int>> pq;
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                // auto [si, n1, n2] = pq.top();
                if (pq.size() < k) {
                    pq.push({sum, nums1[i], nums2[j]});
                } else if (sum < get<0>(pq.top())) {
                    pq.pop();
                    pq.push({sum, nums1[i], nums2[j]});

                } else {
                    break; // after that you get all greter element from nums2
                           // so break the loop
                }
            }
        }
        vector<vector<int>>res;
        while(k--){
             auto [si, n1, n2] = pq.top();
             pq.pop();
            res.push_back({n1,n2});
        }
        
        return res;
    }
};