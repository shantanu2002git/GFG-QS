//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void cal(string &s, int idx, vector<string>&res){
        if(idx>=s.size()){
            res.push_back(s);
        }
        
        for(int i=idx; i<s.size(); i++){
            swap(s[idx],s[i]);
            cal(s,idx+1,res);
            swap(s[idx],s[i]);
        }
    }
    vector<string> permutation(string s)
    {
        vector<string>res;
        cal(s,0,res);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends