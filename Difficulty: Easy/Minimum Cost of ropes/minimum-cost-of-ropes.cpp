//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        multiset<long long> ms(arr.begin(),arr.end());
        long long res=0;
        while(ms.size()>1)
        {
            auto it1=ms.begin();
            long long first=*it1;
            ms.erase(it1);
            auto it2=ms.begin();
            long long second=*it2;
            ms.erase(it2);
            long long cost=first+second;
            res=res+cost;
            ms.insert(cost);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends