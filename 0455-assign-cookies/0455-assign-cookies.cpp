class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       
        if(s.empty()){
            return 0;
        }
        sort(g.begin(),g.end());
        sort(s.begin(), s.end());
        int n=g.size(),m=s.size(),i=0,j=0,res=0;
        while(i<n && j<m){
            if (s[j] >= g[i]) {  // If the cookie can satisfy the child
            i++;  // Move to the next child
        }
        j++;  
        }
        return i;
    }
};