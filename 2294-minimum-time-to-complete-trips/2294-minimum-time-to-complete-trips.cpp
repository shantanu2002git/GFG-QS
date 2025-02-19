#define ll long long

class Solution {
public:
    long long minimumTime(vector<int>& time, int tp) {
        ll lw = 1, hai = (ll)*min_element(time.begin(), time.end()) * tp, res = hai;

        while (lw <= hai) {
            ll md = lw + (hai - lw) / 2;  // Avoid overflow
            ll btime = 0;

            for (auto it : time) {
                btime += md / it; 
            }

            if (btime >= tp) {
                res = md;  // Store valid minimum time
                hai = md - 1;  
            } else {
                lw = md + 1;  
            }
        }
        return res;
    }
};
