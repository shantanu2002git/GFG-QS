class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        // Initialize the left array
        left[0] = (s[0] == '0') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + (s[i] == '0' ? 1 : 0);
        }

        // Initialize the right array
        right[n - 1] = (s[n - 1] == '1') ? 1 : 0;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        // Calculate the maximum score
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            res = max(res, left[i] + right[i + 1]);
        }

        return res;
    }
};
