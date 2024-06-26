//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    string arr=s;
    int n = arr.size(), mx = 0, res = 0;
    int ze = 0, on = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '1')
        {
            ze--;
            on++;
        }
        if (ze < 0)
        {
           
            ze = 0;
        }
        else if (arr[i] == '0')
        {
            ze++;
            mx = max(mx, ze);
            res = max(res, mx - on);
        }
    }
    return mx==0 ? -1 : mx;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends