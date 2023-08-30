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
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       vector<int>res;
       multiset<int>st;
       int wind_strt=0;
       int wind_end=0;
       while(wind_end<k){
           st.insert(arr[wind_end++]);
       }
       
       res.push_back(*st.rbegin());
       while(wind_end<n){
           st.erase(st.find(arr[wind_strt]));
           st.insert(arr[wind_end]);
           res.push_back(*st.rbegin());
           wind_end++;
           wind_strt++;
       }
       return res;
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