//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  bool isIP(string ip){
      int n=ip.size();
      if(n<=0 || n>3){
          return false;
      }
      if(ip[0]=='0' && n>1){
          return false;
      }
      
      int dip=stoi(ip);
      if(dip<0 || dip>255){
          return false;
      }
      return true;
  }
  string createIP(string s, int i, int j, int k, int n){
      string s1=s.substr(0,i+1);
      string s2=s.substr(i+1,j-i);
      string s3=s.substr(j+1,k-j);
      string s4=s.substr(k+1,n-1-k);
      
      if(isIP(s1) && isIP(s2) && isIP(s3) && isIP(s4)){
          return s1+'.'+s2+'.'+s3+'.'+s4;
      }
      return "";
      
  }
    vector<string> genIp(string &s) {
      int n=s.size();
      vector<string>res;
      for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
              for(int k=j+1; k<n; k++){
                  string si=createIP(s,i,j,k,n);
                  if(si.size()>0){
                      res.push_back(si);
                  }
              }
          }
      }
      return res;
    }

};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends