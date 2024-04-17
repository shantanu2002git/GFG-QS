//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution
{
public:
  int minimizeDifference(int n, int k, vector<int> &arr)
  {
    vector<int> rig_mx(n), rig_mi(n);
    rig_mx[n - 1] = arr[n - 1];
    rig_mi[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      rig_mx[i] = max(rig_mx[i + 1], arr[i]);
      rig_mi[i] = min(rig_mi[i + 1], arr[i]);
    }
    rig_mx.push_back(-1e9);
    rig_mi.push_back(1e9);
    int l = 0, r = 0, res = 1e9;
    int mi = 1e9, mx = 0;
    while (l < n)
    {

      if (l - r + 1 == k)
      {
        int mx1 = max(mx, rig_mx[l + 1]);
        int mn1 = min(mi, rig_mi[l + 1]);

        // cout << mx1 << " " << mn1 << endl;
        mi = min(mi, arr[r]);
        mx = max(mx, arr[r]);
        res = min(res, mx1 - mn1);
        r++;
      }

      l++;
    }
    return res;
  }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends