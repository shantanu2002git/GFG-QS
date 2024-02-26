//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
       int op=0,cl=0,unbls=0,sw=0;
       for(auto i : s){
           if(i==']'){
               cl++;
           }else if(i=='['){
               if(unbls>0){
                   sw=sw+unbls;
               }
               op++;
           }
           unbls=cl-op;
       }
       return sw;
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
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends