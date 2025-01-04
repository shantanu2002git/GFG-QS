class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> lefcount(26, 0), rightcount(26, 0);
        map<char, int> index;
        int res = 0;

       
        for (int i = n - 1; i >= 0; i--) {
            if (index.find(s[i]) == index.end()) {
                index[s[i]] = i;
            }
        }

        // Traverse the string and count unique palindromic subsequences
        for (int i = 0; i < n; i++) {
            set<char> st;
            int ci = s[i] - 'a';
            if (lefcount[ci] == 0) {
                for (int j = i + 1; j < index[s[i]]; j++) {
                    st.insert(s[j]);
                }
            }
            lefcount[ci]=1;//already cover
            res += st.size();
        }

        return res;
    }
};
