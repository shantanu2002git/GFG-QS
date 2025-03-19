class Solution {
public:
    string reverseWords(string s) {
        string si = "", res = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                si = s[i] + si;
            } else if (!si.empty()) {
                res = res + si + " ";
                si = "";
            }
        }
        if (!si.empty()) {
            res = res + si;
        }
        if (!res.empty() && res.back() == ' ')
            res.pop_back();
        return res;
    }
};