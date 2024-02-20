//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
int dp[1100][1100];
 map<string,int>mp;
bool call(string s, int idx, int n){
    if(idx==n){
        return 1;
    }
    for(int it=idx; it<n; it++){
        string si=s.substr(idx, it-idx+1);
        if(mp.find(si)!=mp.end()){
            if(call(s,it+1,n)){
                return 1;
            }
        }
    }
    return 0;
}
    int wordBreak(string sa, vector<string> &db) {
        int n=sa.size();
        memset(dp,-1,sizeof(dp));
       
        for(auto it : db){
            mp[it]++;
        }
        return call(sa,0,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends