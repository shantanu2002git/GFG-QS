//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minChange(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << minChange(s) << endl;
    }
return 0;
}

// } Driver Code Ends


int minChange(string s) { 
   map<int,int>mp;
   int n=s.size();
   for(int i=0; i<n; i++){
       mp[s[i]]++;
   }
   
   int ss=0;
   for(auto it : mp)
   {
       int x=it.second;
       ss=ss+(x-1);
   }
   return ss;
} 
