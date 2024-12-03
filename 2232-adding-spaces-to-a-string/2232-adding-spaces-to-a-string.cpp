class Solution
{
public:
    string addSpaces(string s, vector<int> &sp)
    {
        sort(sp.begin(), sp.end()); 
        int n = sp.size();
        string res = "";
        int l = 0;

        for (int i = 0; i < s.size(); i++)
        {
                if (l < n && sp[l] == i)
            {
                res += " ";
                l++; 
            }
            res += s[i];
        }
        
        return res;
    }
};
