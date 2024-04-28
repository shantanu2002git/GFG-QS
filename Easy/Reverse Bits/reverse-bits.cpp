//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        long ans=0;
        int index=31;
        
        while(x!=0){
            if(x%2==1){
                 ans+=pow(2,index);//T.C. - O(log(X)) , S.C. - O(1)
                
            }
            index--;
            x=x/2;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends