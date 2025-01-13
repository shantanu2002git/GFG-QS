class Solution
{
public:
    struct Node {
        int count;
        int index;
        Node() : count(0), index(0) {}
    };

    int minimumLength(string s)
    {
        int n = s.size();
        map<char, int> mpl;
        map<int, map<char, Node>> lst;

        // Build the `lst` map with cumulative counts
        for (int i = n - 1; i >= 0; i--)
        {
            mpl[s[i]]++;
            Node node;
            node.count = mpl[s[i]];
            node.index = i;
            lst[i][s[i]] = node;
        }

        map<char, int> mpfs; 
        int tic = n; // Initial length of the string

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+') {
                tic--;
                continue; // Skip already deleted characters
            }

            int fs = mpfs[s[i]]; // Frequency of s[i] in the prefix
            auto tp = lst[i]; // Map of counts at index i

            // Next frequency of the current character
            int ls = tp[s[i]].count - 1;

            if (fs > 0 && ls > 0)
            {
                // Update the node count in lst
                lst[i][s[i]].count = ls;

                // Mark character as deleted
                s[lst[i][s[i]].index] = '+';
                tic--; // Decrease length
            }

            // Update prefix frequency
            mpfs[s[i]]++;
        }
        cout<<s;

        return tic;
    }
};
