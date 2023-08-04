//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int cal_sml(vector<int>&mtx, int k){
    int lw=0,hi=mtx.size()-1;
    while(lw<=hi){
        int md=(lw+hi)/2;
        if(mtx[md]<=k){
            lw=md+1;
        }else{
            hi=md-1;
        }
    }
    return lw;
}
    int median(vector<vector<int>> &matrix, int R, int C){
        int mn=1e9,mx=-1e9;
        for(int i=0; i<R; i++){
            mn=min(matrix[i][0],mn);
            mx=max(matrix[i][C-1],mx);
        }
        
        while(mn<=mx){
            int md=(mn+mx)/2;
            int cnt=0,may_md=(R*C)/2;
            
            for(int i=0; i<R; i++){
                cnt=cnt+cal_sml(matrix[i],md);
            }
            
            if(cnt>may_md){
                mx=md-1;
            }else {
                mn=md+1;
            }
        }
        return mn;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends