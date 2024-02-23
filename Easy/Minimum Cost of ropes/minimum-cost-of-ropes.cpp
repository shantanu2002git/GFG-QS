//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
    long long s=0;
   priority_queue<long long>pq;
    for(int i=0; i<n; i++){
        pq.push(-arr[i]);
    }
    long long res=0;
    while(pq.size()!=1){
        long long n1=pq.top();
        pq.pop();
        long long n2=pq.top();
        pq.pop();
        s=(n1+n2);
        res=res+s;
        pq.push(s);
    }
    return -res;
    }
};

/*

17 99 11 2 34

min : 2 11 17 34 99 <.....>
max : 99 34 17 11 2 pqr<int>pq

pq.push(-17,-99,-11,-2,-34) : max
-2 -11 -17 -34 -99

{4, 3, 2, 6}
-4 -3 -2 -6
pq: -2 -3 -4 -6
 
 n1=-2,n2=-3
 s1=-5
 
 -4 -5 -6
 
 s2=-9
 
 -6 -9
 s3=-15
 
 return -s3;
 


*/


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends