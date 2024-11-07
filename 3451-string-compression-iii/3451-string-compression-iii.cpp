class Solution {
public:
    string compressedString(string w) {
        int n = w.size(), i = 1, c = 1;
        string res = "";
        while (i < n)
        {

            while (w[i - 1] == w[i] && i < n && c < 9)
            {
                c++;
                i++;
            }
            res.append(to_string(c));
            res.push_back(w[i - 1]);
            c = 1;
            i++;
        }
        return res; 
    }
};