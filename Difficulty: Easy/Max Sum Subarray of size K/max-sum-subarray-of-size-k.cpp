class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxres=0;
        int i=0,j=0,s=0;
        while(i<n){
            s=s+arr[i];
           
            while(i-j+1>k){
                s=s-arr[j];
                j++;
            }
             if(i-j+1==k){
                // cout<<s<<" ";
                maxres=max(maxres,s);
            }
            i++;
        }
        maxres=max(maxres,s);
        return maxres;
    }
};