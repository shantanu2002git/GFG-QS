class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> fq;
        for (auto it : words) {
            fq[it]++;
        }
        int res = 0;
        bool centerUsed = 0;
        for (auto [si, cnt] : fq) {

            string rev = si;
            reverse(rev.begin(), rev.end());
            if (rev == si) {
                int pairs = cnt / 2;
                res += pairs * 4; // Each pair contributes 4 to length
                fq[si] -= pairs * 2;

                // Use one single symmetric word in the center if any left
                if (fq[si] > 0 && !centerUsed) {
                    res += 2;
                    centerUsed = true;
                }
            } else if (fq.find(rev) != fq.end()) {
                int pirc = min(fq[si], fq[rev]);
                res = res + (pirc * 4);
                fq[si] -= pirc;
                fq[rev] -= pirc;
            }
        }

        return res;
    }
};