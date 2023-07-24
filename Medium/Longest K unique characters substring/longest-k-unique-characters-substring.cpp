//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int i=0,j=0,n=s.size(),mx=-1;
    map<char,int>mp;
    while(i<n){
        mp[s[i]]++;
        if(mp.size()==k){
            mx=max(mx,(i-j+1));
        }
        
        while(mp.size()>k) {
            mp[s[j]]--;
            if(mp[s[j]]==0){
                mp.erase(s[j]);
            }
            j++;
        }
         if(mp.size()==k){
            mx=max(mx,(i-j+1));
        }
        i++;
    }
    return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends