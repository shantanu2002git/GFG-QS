//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    vector<long long> res;
    deque<int> dq;
    long long int i;

   
    for (i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

 
    while (i < n) {
      
        if (!dq.empty()) {
            res.push_back(arr[dq.front()]);
        } else {
            res.push_back(0);
        }

       
        while (!dq.empty() && dq.front() < (i - k + 1)) {
            dq.pop_front();
        }

        // Add the current element at the end of the deque if it is negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }
        i++;
    }

    // Append the first negative integer for the last window
    if (!dq.empty()) {
        res.push_back(arr[dq.front()]);
    } else {
        res.push_back(0);
    }

    return res;
}

                                                 