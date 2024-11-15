class Solution {
public:
    vector<string> res;
    void call(string di, int idx, string in, vector<string> let) {
        if (idx == di.size()) {
            if (!in.empty()) {
                res.push_back(in);
            }

            return;
        }
        for (char i : let[di[idx] - '0']) {
            in.push_back(i);
            call(di, idx + 1, in, let);
            in.pop_back();
        }
    }
    vector<string> letterCombinations(string di) {
        map<int, string> mps{{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                             {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        vector<string> letter{"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        call(di, 0, "", letter);

        return res;
    }
};