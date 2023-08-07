//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool H_isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

	int minStepToReachTarget(vector<int>&ki, vector<int>&tp, int N){
	   int x=ki[0],y=ki[1];
	   int tx=tp[0],ty=tp[1];
	   queue<pair<int,pair<int,int>>>q;
	   q.push({0,{x,y}});//dis-x-y
       vector<vector<int>>vis(N+1,(vector<int>(N+1,1)));
       vis[x][y]=0;
       while(!q.empty()){
          int n=q.size();
          while(n--){
            auto it =q.front();
            q.pop();
            int dis=it.first,xi=it.second.first,yi=it.second.second;
            if(xi==tx && ty==yi){
                return dis;
            }
            for(int i=0; i<8; i++){
                int nx=dx[i]+xi;
                int ny=dy[i]+yi;

                if(H_isInside(nx,ny,N) && vis[nx][ny] ){
                    q.push({dis+1,{nx,ny}});
                    vis[nx][ny]=0;
                    
                }
            }
          }
       }
	   
	   return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends