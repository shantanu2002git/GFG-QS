class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) {
            return 0;
        }
        /* nlogn*/
        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                return 0;
            }
        }
        return 1;
        */

        vector<int> mps(26, 0);
        for (auto i : s) {
            mps[i - 'a']++;
        }
        for (auto j : t) {
            mps[j - 'a']--;
        }
        for (int it : mps) {
            if (it < 0) {
                return 0;
            }
        }
        return 1;
    }
};