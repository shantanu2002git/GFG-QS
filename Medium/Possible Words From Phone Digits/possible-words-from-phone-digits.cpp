//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int a[], int idx, int n, vector<string>&val, string add, vector<string>&ans){
     if(idx==n){
         ans.push_back(add);
         return;
     }   
     
     for(auto it : val[a[idx]]){
         add.push_back(it);
         solve(a,idx+1,n,val,add,ans);
         add.pop_back();
         
     }
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector <string> val = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> ans;
        
        solve(a, 0, n, val, "", ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends