//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        vector<int> result;
        if (k == 0)
            return result;
        priority_queue<pair<int, int>> w;
        // int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!w.empty() && w.top().second <= i - k) {
                w.pop();
            }
            w.push(make_pair(nums[i], i));
            if (i >= k - 1) {
                result.push_back(w.top().first);
            }
        }
        return result;
    }
};




//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends