//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int isGoodorBad(string s) {
       int n=s.size();
       int vl=0,cs=0,qs=0,bol=1,con=0;
       set<char>st{'a','e','i','o','u'};
       for(int i=0; i<n; i++){
          
          if(s[i]=='?'){
            cs++;
            vl++;
           }
            else if(st.count(s[i])){
            vl++;
            cs=0;
           }else{
            cs++;vl=0;
           }
          if((vl>5) || (cs>3 )){
            return 0;
          }
       }
       return 1;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends