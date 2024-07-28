//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int>lef_min(n),rig_max(n);
        lef_min[0]=arr[0];
        for(int i=1; i<n; i++){
            lef_min[i]=min(lef_min[i-1],arr[i]);
        }
        rig_max[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            rig_max[i]=max(rig_max[i+1],arr[i]);
        }
        int ix=0,jx=0,mx=-1e9;
        while(ix<n && jx<n){
            if(lef_min[ix]<=rig_max[jx]){
                mx=max(mx,jx-ix);
                jx++;
            }else{
                ix++;
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends