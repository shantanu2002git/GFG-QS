//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:    
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp.insert({0,-1});
        int s = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
            int rem = (s % k + k) % k; // Ensure rem is non-negative
            if (mp.find(rem) == mp.end()) {
                mp.insert({rem, i});
            } else {
                mx = max(mx, i - mp[rem]);
            }
        }
        return mx;
    }
};




//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends