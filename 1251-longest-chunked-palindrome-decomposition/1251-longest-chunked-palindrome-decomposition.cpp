class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int res = 0;
        string left = "", right = "";

        for (int i = 0; i < n; i++) {
            left = left + text[i];
            right = text[n - i - 1] + right;
            if (left == right) {
                res++;
                 left = "", right = "";
                 //need to make it logest so reset after finding correct match
            }
        }
        return res;
    }
};