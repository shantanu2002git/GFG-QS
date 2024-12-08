class Solution
{
public:
    int maxCount(vector<int> &bann, int n, int target)
    {
        sort(bann.begin(), bann.end()); 
        int res = 0;                
        int currentSum = 0;          
        
        for (int i = 1; i <= n; i++)
        {
           
            if (binary_search(bann.begin(), bann.end(), i))
                continue; // Skip this number if it is banned
            
            if (currentSum + i <= target)
            {
                res++;         
                currentSum += i; 
            }
            else
            {
                break; 
            }
        }
        return res; 
    }
};
