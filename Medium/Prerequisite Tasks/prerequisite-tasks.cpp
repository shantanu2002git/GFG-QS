//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	  int n=N;
	  vector<int>in(n,0);
	 vector<int>nwadj[n];
	 for(auto it : pre){
	     nwadj[it.first].push_back(it.second);
	 }
	 for(int i=0; i<n; i++){
	     for(auto it : nwadj[i]){
	         in[it]++;
	     }
	 }
	 queue<int>q;
	 for(int i=0; i<n; i++){
	     if(in[i]==0){
	         q.push(i);
	     }
	 }
	 
	 int cp=0;
	 vector<int>res;
	 while(!q.empty()){
	     int nx=q.size();
	     while(nx--){
	         int f=q.front();
	         q.pop();
	         cp++;
	         res.push_back(f);
	         for(auto t : nwadj[f]){
	             in[t]--;
	             if(in[t]==0){
	                 q.push(t);
	             }
	         }
	     }
	 }
	 return cp==n;
	}
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends