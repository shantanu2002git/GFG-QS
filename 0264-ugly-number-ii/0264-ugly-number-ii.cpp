class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0]=1;
        int i2=0, i3=0, i5=0;
        for(int i=1; i<n; i++){
            int nx2=ugly[i2]*2;
            int nx3=ugly[i3]*3;
            int nx5=ugly[i5]*5;

            ugly[i]=min({nx2,nx3,nx5});

            if(ugly[i]==nx2) i2++;
            if(ugly[i]==nx3) i3++;
            if(ugly[i]==nx5) i5++;

        }

        return ugly[n-1];
    }
};