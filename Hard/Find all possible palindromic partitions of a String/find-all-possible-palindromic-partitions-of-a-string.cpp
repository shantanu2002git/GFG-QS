//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> res;

    bool palindrome(string si) {
        int i = 0, j = si.size() - 1;
        while (i <= j) {
            if (si[i] != si[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void cal(string &s, int idx, vector<string> &in) {
        if (idx >= s.size()) {
            res.push_back(in);
            return;
        }
        string str = "";
        for (int k = idx; k < s.size(); k++) {
            str = str + s[k];
            if (palindrome(str)) {
                in.push_back(str);
                cal(s, k + 1, in);
                in.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> allPalindromicPerms(string S) {
        vector<string> in;
        cal(S, 0, in);
        return res;
    }
}; 



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends