//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    vector<string> res;

    void call(int i, int n, string s, string in) {
        if (i == n) {
            if (!in.empty()) {
                res.push_back(in);
            }
            return;
        }
        in.push_back(s[i]);
        call(i + 1, n, s, in);
        in.pop_back();
        call(i + 1, n, s, in);
    }

    vector<string> AllPossibleStrings(string s) {
        int n = s.size();

        call(0, n, s, "");
        sort(res.begin(),res.end());
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