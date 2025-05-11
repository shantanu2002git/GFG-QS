class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        vector<int>vp;
        for(auto it : mp){
            vp.push_back(it.second);
        }
        sort(vp.begin(), vp.end(), greater<int>());
        int res=0;
        for(int i=0; i<vp.size(); i++){
            if(k<=0){
                res=res+vp[i];
            }
            k--;
        }

        return res;


    }
};