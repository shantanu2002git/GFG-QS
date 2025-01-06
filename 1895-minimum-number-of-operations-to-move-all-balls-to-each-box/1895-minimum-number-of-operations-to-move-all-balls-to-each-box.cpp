
class Solution
{
public:
    vector<int> minOperations(string box)
    {
        int n = box.size();

        vector<int> res;
       

        for (int i = 0; i < n; i++)
        {
             int pls = 0;
            for (int l = i; l >= 0; l--)
            {
                if (box[l] == '1')
                {
                    pls = pls + abs(l - i);
                }
            }

            for (int m = i; m < n; m++)
            {
                if (box[m] == '1')
                {
                    pls = pls + abs(m - i);
                }
            }

            cout<<pls<<" ";

            res.push_back(pls);

        }
        return res;
    }
};
