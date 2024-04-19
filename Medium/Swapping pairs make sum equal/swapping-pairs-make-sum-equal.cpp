//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findSwapValues(int A[], int n, int B[], int m) {
        int as = 0, bs = 0;
        for (int i = 0; i < n; i++) {
            as += A[i];
        }
        for (int j = 0; j < m; j++) {
            bs += B[j];
        }
        
        int diff = abs(as - bs);
        if(diff==0){
            return 1;
        }
        if (diff % 2 != 0){
            return -1;
            
        }
        // diff /= 2; 
        
       sort(B, B + m); // Sort B array for binary search
        
        for (int i = 0; i < n; i++) {
            int target = -A[i] + diff;
            if (binary_search(B, B + m, target)) {
                return 1; 
            }
        }
        return -1; 
    }
};




//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends