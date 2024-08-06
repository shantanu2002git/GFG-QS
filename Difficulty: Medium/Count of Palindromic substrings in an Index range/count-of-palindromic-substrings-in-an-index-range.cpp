//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countPalinInRange (int n, string A, int q1, int q2);
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int q1, q2; cin >> q1 >> q2;
		cout << countPalinInRange (n, s, q1, q2) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int countPalinInRange (int n, string s, int x1, int x2)
{
    int res=0;
    int q1=min(x1,x2),q2=max(x1,x2);
    for(int i=q1; i<=q2; i++){
        int lf=i,rg=i,cnt=0;
        //odd;
        while(lf>=q1 && rg<=q2 && s[lf]==s[rg]){
            lf--;
            rg++;
            cnt++;
        }
        res=res+cnt;
        //even
        lf=i,rg=i+1,cnt=0;
       while(lf>=q1 && rg<=q2 && s[lf]==s[rg]){
            lf--;
            rg++;
            cnt++;
        }
         res=res+cnt;
    }
    return res;
}