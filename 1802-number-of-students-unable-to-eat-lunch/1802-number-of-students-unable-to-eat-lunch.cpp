class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int j = 0, n = students.size();
        int zer = 0, one = 0;
        for (auto i : students) {
            if (i) {
                one++;
            } else {
                zer++;
            }
        }
        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        while (!q.empty()) {
            int tp = q.front();
            if (tp != sandwiches[j]) {
                q.push(q.front());
                q.pop();
                if((sandwiches[j]==0 && zer==0) || (sandwiches[j]==1 && one==0)){
                    break;
                }
            } else {
                if (tp) {
                    one--;
                } else {
                    zer--;
                }
                q.pop();
                j++;
            }
        }
        return n - j ;
    }
};