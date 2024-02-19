//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
       map<int,int>mp;
       int n=s.size();
       for(int i=0; i<n; i++){
           mp[s[i]]++;
       }
       priority_queue<int>pq;
       for(auto it : mp ){
           pq.push(it.second);
       }
       
       while(k--){
           int tp=pq.top();
           tp=tp-1;
           pq.pop();
           pq.push(tp);
           
       }
       long long res=0;
       while(!pq.empty()){
           int tpp=pq.top();
           pq.pop();
           res=res+(tpp*tpp);
       }
       return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends