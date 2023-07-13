//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
void cal(int idx, string sr, string s, vector<string>&res){
    if(idx==s.size()-1){
        sr=sr+s[idx];
        res.push_back(sr);
        return;
        
    }
    
    cal(idx+1,sr+s[idx]+" ",s,res);
    cal(idx+1,sr+s[idx],s,res);
}
    vector<string> permutation(string s){
       vector<string>res;
       string sr="";
       cal(0,sr,s,res);
       return res;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends