class Solution
{
public:
    string makeFancyString(string s)
    {
       int n=s.size();
       string ans="";
       for(int i=0; i<n; i++){
             if(i==0 || s[i]!=s[i-1]){
               ans+=s[i];
           }else if(i>1 && s[i]==s[i-1] && s[i]==s[i-2]){
               continue;
           }else{
            ans+=s[i];
           }
    }
    return ans;
    }
};