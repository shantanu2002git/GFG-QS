class Solution {
public:
    bool valid(string s, string t) {
        int n = s.size(), m = t.size(), smp[256] = {0}, tmp[256] = {0};

        if (n != m)
            return false;
        for (int i = 0; i < min(n, m); i++) {
            if (smp[s[i]] != tmp[t[i]]) {
                return false;
            }
            smp[s[i]] = i + 1;
            tmp[t[i]] = i + 1;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> res;
        for (auto it : words) {
            if (valid(it, pattern)) {
                res.push_back(it);
            }
        }
        return res;
    }
};