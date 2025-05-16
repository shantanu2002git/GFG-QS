#define ll long long

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<ll> fib;
        fib.push_back(1);
        fib.push_back(1);
        for (int i = 2; fib[i - 2] + fib[i - 1] <= k; i++) {

            fib.push_back(fib[i - 2] + fib[i - 1]);
        }

        int res = 0, en = fib.size() - 1;
        while (true) {
            res += k / fib[en];
            k = k % fib[en];
            if (k == 0) {
                break;
            }
            en--;
        }
        return res;
    }
};