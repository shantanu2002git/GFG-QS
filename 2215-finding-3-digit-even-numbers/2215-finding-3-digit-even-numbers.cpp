class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> result;

        for (int num = 100; num <= 999; num++) {
            if ((num % 2) != 0) continue; // must end in even digit

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> temp(10, 0);
            temp[a]++;
            temp[b]++;
            temp[c]++;

            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (temp[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(num);
        }

        return result;
    }
};
