//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
  int i=0,j=0,mx=-1,n=s.size();
  map<char,int>mp;
  while(i<n){
    mp[s[i]]++;
    while(mp.size()>k){
      mp[s[j]]--;
      if(mp[s[j]]==0){
        mp.erase(s[j]);
      }
      j++;
    }
    mx=max(mx,i-j+1);
    i++;
  }
  return (mx>=k ? mx : -1);
    
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