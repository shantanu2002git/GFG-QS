//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void cal(int idx, string s, set<string>&ans){
	    if(idx==s.size()){
	        ans.insert(s);
	        return;
	    }
	    for(int i=idx ; i<s.size(); i++){
	        swap(s[idx],s[i]);
	        cal(idx+1,s,ans);
	        swap(s[idx],s[i]);
	    }
	}
		vector<string>find_permutation(string s)
		{
		   set<string>ans;
		   cal(0,s,ans);
		   vector<string>result(ans.begin(),ans.end());
		   return result;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends