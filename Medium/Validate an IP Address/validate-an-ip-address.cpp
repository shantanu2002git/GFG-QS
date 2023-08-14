//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
          int n = s.size();
	if (n < 7)
		return false;
		
	vector<string> v;
string si="";
for(int i=0; i<n+1; i++){
if(s[i]=='.' || i==n){
// cout<<si<<" ";
 v.push_back(si);
 si="";
 continue;
}
si=si+s[i];
}


	if (v.size() != 4)
		return false;
	
	for (int i = 0; i < v.size(); i++) {

		string temp = v[i];
   
		if (temp.size() > 1) {
			if (temp[0] == '0')
				return false;
		}
     	for (int j = 0; j < temp.size(); j++) {
			if (isalpha(temp[j]) || stoi(temp)<0 || stoi(temp)>255)
				return false;
		}
		
	}
	return true;
}
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends