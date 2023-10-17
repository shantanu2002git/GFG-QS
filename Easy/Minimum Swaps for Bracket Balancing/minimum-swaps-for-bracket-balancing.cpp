//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        int cnt=0,n=s.size(),open=0;
        for(int i=0; i<n; i++){
            if(s[i]=='['){
                cnt++;
            }else{
                //close
                cnt--;
                if(cnt<0){
                    open=open-cnt;
                }
            }
        }
        return open;
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