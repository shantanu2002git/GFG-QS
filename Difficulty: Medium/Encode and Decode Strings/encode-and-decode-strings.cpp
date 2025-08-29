class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string si;
        for(auto it : s){
            si=si+"+"+it;
        }
        return si+"+";
    }

    vector<string> decode(string& s) {
        
        // code here
        vector<string>res;
        string ss="";
        for(auto c : s){
            if(c=='+'){
                res.push_back(ss);
ss="";
continue;
            }
            ss=ss+c;
        }
        return res;
    }
};