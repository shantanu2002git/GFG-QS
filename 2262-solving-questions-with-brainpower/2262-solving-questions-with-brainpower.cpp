class Solution {
public:
    int call(vector<vector<int>>& q, int idx, int n, int vl) {
        if (idx >= n) {
            return 0;
        }
        int tt = 0, nn = 0;
        tt = q[idx][0] + call(q, idx + q[idx][1] + 1, n, vl);
        nn = call(q, idx + 1, n, vl);

        return max(tt, nn);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // return call(questions, 0, n, 0);

        long long dp[200005] = {};
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(questions[i][0] + dp[questions[i][1] + i + 1], dp[i + 1]);
        }
        return dp[0];
    }
};