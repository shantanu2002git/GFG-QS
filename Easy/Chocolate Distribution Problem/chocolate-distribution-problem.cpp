//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
   // [1 3 4 7 9 9 12 56]
   int mn=1e9,i=0,j=0;
   while(i<n){
      
       if(i-j+1==m){
        //cout<<a[j]<<"   " <<j<<" "<<a[i]<<" "<<i<<endl;
       if(mn>(a[i]-a[j])){
        mn=(a[i]-a[j]);
       }
       j++;
       }
       
       i++;
   }
   return mn;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends