class Solution
{
public:
    bool is_Spesial(string sp)
    {
        int m = sp.size();
        for (int i = 1; i < m; i++)
        {
            if (sp[i - 1] != sp[i])
            {
                return false;
            }
        }
        return true;
    }
    int maximumLength(string s)
    {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                string sub = s.substr(i, j);
                if (is_Spesial(sub))
                {
                    mp[sub]++;
                }
            }
        }
        int res = -1;
        for (auto it : mp)
        {
            if (it.second >= 3)
            {
                int len = it.first.size();
                if (res < len)
                {
                    res = len;
                }
            }
        }
        return res;
    }
};
