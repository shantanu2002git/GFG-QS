//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int row_max_sum = 0;
        int row_curr_sum[n] = {0,};
        int col_max_sum = 0;
        int col_curr_sum[n] = {0,};
        int row_res = 0;
        int col_res = 0;
        
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {
                row_curr_sum[i] += matrix[i][j];
                col_curr_sum[i] += matrix[j][i];
            }
            row_max_sum = max(row_max_sum,row_curr_sum[i]);
            col_max_sum = max(col_max_sum,col_curr_sum[i]);
        }
        
        for(int i=0;i<n;i++)
        {
           row_res += row_max_sum - row_curr_sum[i] ;
           col_res += col_max_sum - col_curr_sum[i] ;
        }
        return max(row_res,col_res);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends