#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int> mpa1;
        for (auto it : arr1) {
            string nws = to_string(it);
            for (int i = 1; i <= nws.size(); i++) { // Include the full string
                string subs = nws.substr(0, i);
                mpa1[subs]++;
            }
        }

        int maxLength = 0;
        for (auto it : arr2) {
            string nws = to_string(it);
            for (int i = 1; i <= nws.size(); i++) { // Include the full string
                string subs = nws.substr(0, i);
                if (mpa1.find(subs) != mpa1.end()) {
                    maxLength = max(maxLength, (int)subs.size());
                }
            }
        }

        return maxLength; // Return the length of the longest common prefix
    }
};
