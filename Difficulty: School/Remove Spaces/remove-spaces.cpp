//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string modify (string s)
    {
        int n=s.size();
        string si="";
        for(int i=0; i<n; i++){
            while(s[i]==' ' && i<n){
                i++;
            }
            si=si+s[i];
        }
        return si;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
    return 0;
}


// } Driver Code Ends