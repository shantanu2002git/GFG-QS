//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    int rw=mat.size();
	    int cl=mat[0].size();
	    
	    for(int i=0;i<rw; i++){
	        for(int j=0; j<cl; j++){
	            if(mat[i][j]==-1){
	                mat[i][j]=0;
	            }
	        }
	    }
	    
	    
	    for(int i=0; i<rw; i++){
	        for(int j=0; j<cl; j++){
	            if(mat[i][j]==0 && i!=j){
	                mat[i][j]=999999;
	            }
	        }
	    }
	    
	    
	    for(int k=0; k<mat.size(); k++){
	        for(int i=0; i<rw; i++){
	            for(int j=0; j<cl; j++){
	                if(mat[i][k]+mat[k][j]<mat[i][j]){
	                    mat[i][j]=mat[i][k]+mat[k][j];
	                }
	            }
	        }
	    }
	    
	    
	    for(int i=0; i<rw; i++){
	        for(int j=0; j<cl; j++){
	            if(mat[i][j]==999999 && i==j){
	                mat[i][j]=0;
	            }else if(mat[i][j]==999999 && i!=j){
	                mat[i][j]=-1;
	            }
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends