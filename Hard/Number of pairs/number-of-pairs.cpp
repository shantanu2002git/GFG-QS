//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long long int numberOfPairs(vector<vector<int>>& pairs, int p, int n) {
        // Creating an adjacency list to represent the graph
        vector<vector<int>> adjList(n);
        for (auto& pair : pairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        vector<bool> visited(n, false);
        vector<int> componentSizes;

        // Function to perform BFS and calculate the size of each connected component
        auto bfs = [&](int start) {
            queue<int> q;
            q.push(start);
            visited[start] = true;
            int componentSize = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                componentSize++;

                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            return componentSize;
        };

        // Calculating sizes of connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int componentSize = bfs(i);
                componentSizes.push_back(componentSize);
            }
        }

        // Calculating the total number of pairs
        long long totalPairs = 0;
        long long sumOfSizes = 0;
        for (int size : componentSizes) {
            totalPairs += size * sumOfSizes;
            sumOfSizes += size;
        }

        return totalPairs;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        vector<vector<int>> pairs(p,vector<int>(2));
        for(auto &i:pairs)
            for(auto &j:i)
                cin>>j;
        Solution a;
        cout<<a.numberOfPairs(pairs,p,n)<<endl;
    }
}
// } Driver Code Ends