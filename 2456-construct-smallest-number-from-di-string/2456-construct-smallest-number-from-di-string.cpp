class Solution {
public:

bool visit[10] = {0}; 
string ans = ""; 
bool found = false; // Flag to stop recursion early

void call(string &pat, int idx, string &res) {
    if (found) return; // Stop if already found the answer
    if (idx == pat.size()) { // Base case: sequence complete
        ans = res;
        found = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (visit[i]) continue;

        if ((pat[idx] == 'I' && res.back() - '0' < i) || 
            (pat[idx] == 'D' && res.back() - '0' > i)) {
            
            res += to_string(i);  // Append the valid number
            visit[i] = true;
            
            call(pat, idx + 1, res);
            
            res.pop_back(); // Backtrack
            visit[i] = false;
        }
    }
}

string smallestNumber(string pattern) {
    for (int i = 1; i <= 9; i++) { 
        string res = to_string(i); // Start with the smallest available number
        visit[i] = true;
        call(pattern, 0, res);
        visit[i] = false;
        if (found) break; // Stop when we find the lexicographically smallest sequence
    }
    return ans;
}

// int main() {
//     string pattern;
//     cin >> pattern;
//     cout << smallestNumber(pattern) << endl;
//     return 0;
// }

};