class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int low=0,hai=n;
        vector<int>res(n+1);
        // res.push_bacK()
        for(int i=0; i<=n; i++){
            if(s[i]=='I'){
                res[i]=low;
                low++;
            }else{
                res[i]=hai;
                hai--;
            }
        }
        return res;
    }
};