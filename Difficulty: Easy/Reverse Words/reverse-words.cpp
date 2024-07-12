//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string si="",res="";
        s="."+s+".";
        
        int n=s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]=='.'){
                reverse(si.begin(),si.end());
                res=res+si;
                si="";
               
            }
            si=si+s[i];
        }
        res.pop_back();
        return res;
       
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends