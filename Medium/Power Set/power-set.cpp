//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void call(int idx, int n, string in, string s, vector<string> &res)
    {
        if (idx == n)
        {
           if (!in.empty()) // is not empty before adding to res
                res.push_back(in);
            return;
        }

        // Include the character at idx
        in.push_back(s[idx]);
        call(idx + 1, n, in, s, res);
        in.pop_back(); 
        // Exclude the character at idx
        call(idx + 1, n, in, s, res);
    }
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> res;
        int n = s.size();
        string in;
        call(0, n, in, s, res);
        sort(res.begin(), res.end());
        return res;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends