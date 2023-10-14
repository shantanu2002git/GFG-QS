//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>res;
    void Backtrack(int i, int j, vector<vector<int>> &mtx, int n, string mov ){
        if(i>=n || j>=n || i<0 || j<0 || mtx[i][j]==0){
            return ;
        }
        
        if(i==n-1 && j==n-1){
            res.push_back(mov);
            mov="";
            return;
        }
        
        mtx[i][j]=0;
        Backtrack(i,j+1,mtx,n,mov+"R");
        Backtrack(i,j-1,mtx,n,mov+"L");
        Backtrack(i+1,j,mtx,n,mov+"D");
        Backtrack(i-1,j,mtx,n,mov+"U");
        mtx[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &mtx, int n) {
        string str="";
        if(mtx[0][0]==0 || mtx[n-1][n-1]==0){
            return {};
        }
        
        Backtrack(0,0,mtx,n,str);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends