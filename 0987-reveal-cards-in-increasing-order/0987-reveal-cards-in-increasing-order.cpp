class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>res(n);
        sort(deck.begin(), deck.end());

        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
/*
[17,13,11,2,3,5,7]
[2 3 5 7 11 13 17 ]
*/
        for(int j=0; j<n; j++){
            int idx=q.front(); q.pop(); //0 2 4
              res[idx]=deck[j];// 2 3 5
              if(!q.empty()){
                int nxt=q.front(); 
                q.pop();
                q.push(nxt);
               
              }
        }

        return res;
    }
};