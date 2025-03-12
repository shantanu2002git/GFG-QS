class Solution {
public:
    int maxArea(vector<int>& hei) {
        int n = hei.size();

        int i = 0, j = n - 1;
        int res = -1e9;
        while (i <= j) {
            int wd = (j - i );

            res = max(res, (wd * min(hei[i], hei[j])));
            if (hei[i] < hei[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};