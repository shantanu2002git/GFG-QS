//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>arr;
       for(int i=0 ; i<n;i++){
           arr.push_back({start[i],end[i]});
       }
       
       sort(arr.begin(),arr.end(),[](const pair<int,int>a1, const pair<int,int>a2){
           return a1.second<a2.second;
       });
       
       int c=1;
       int ed=arr[0].second;
       for(int i=1; i<n; i++)
       {
           if(ed<arr[i].first){
               c++;
               ed=arr[i].second;
           }
       }
       return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends