//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

void calDFS(int x, int y, vector<vector<char>> &mat ,int n, int m){
if(x<0 || x>=n || y<0 || y>=m || mat[x][y]=='X'){
    return ;
}

if(mat[x][y]=='O'){
    mat[x][y]='.';
    calDFS(x-1,y,mat,n,m);
    calDFS(x+1,y,mat,n,m);
    calDFS(x,y-1,mat,n,m);
    calDFS(x,y+1,mat,n,m);
}
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       for(int i=0; i<n; i++){
        if(mat[i][0]=='O'){
            calDFS(i,0,mat,n,m);
        }
        if(mat[i][m-1]=='O'){
            calDFS(i,m-1,mat,n,m);
        }
        for(int j=0; j<m; j++){
            if(mat[0][j]=='O' ){
                calDFS(0,j,mat,n,m);
            }
            if(mat[n-1][j]=='O'){
                calDFS(n-1,j,mat,n,m);
            }
        }
       }

for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(mat[i][j]=='O'){
            mat[i][j]='X';
        }
        if(mat[i][j]=='.'){
            mat[i][j]='O';
        }
    }
}

    //    for(auto it : mat){
    //     for(auto i : it){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    //    }

    return mat;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends