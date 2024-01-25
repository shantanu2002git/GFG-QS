//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
  void call_noCycle_noUnconnect(int nd, vector<int>nwadj[], vector<int>&vis ){
      vis[nd]=1;
      for(auto it : nwadj[nd]){
          if(vis[it]==0){
              call_noCycle_noUnconnect(it,nwadj,vis);
          }
      }
  }
    int isTree(int n, int m, vector<vector<int>> &adj) {
       if((n-m)!=1){
           return 0;
       }
       vector<int>vis(n,0);
       vector<int>nwadj[n];
       
       for(auto it : adj){
           nwadj[it[0]].push_back(it[1]);
           nwadj[it[1]].push_back(it[0]);
       }
       
       call_noCycle_noUnconnect(0,nwadj,vis);
       
       for(auto x : vis){
           if(x==0){
               return 0;
           }
       }
       return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends