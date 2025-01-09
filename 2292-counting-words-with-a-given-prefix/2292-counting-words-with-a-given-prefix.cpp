class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pn=pref.size(),res=0;
        for(auto it : words){
            string sub=it.substr(0,pn);
            if(sub==pref){
                res++;
            }
        }
        return res;
    }
};