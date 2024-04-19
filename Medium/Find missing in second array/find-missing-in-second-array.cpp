//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findMissing(int a[], int b[], int n, int m) { 
        sort(b, b + m);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int vl = a[i], j = 0, mid, fl = 1; 
            int low = 0, high = m - 1;

            // Binary search to find if vl exists in b
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (b[mid] == vl) {
                    fl = 0; // Found, set fl to 0
                    break;
                } else if (b[mid] < vl) {
                    low = mid + 1; 
                } else {
                    high = mid - 1; 
                }
            }

            if (fl) {
                res.push_back(vl); 
            }
        }
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
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends