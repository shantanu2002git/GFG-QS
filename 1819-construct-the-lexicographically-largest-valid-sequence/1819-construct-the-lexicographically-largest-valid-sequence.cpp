class Solution {
public:
    int maxNum, seqLength;
    bitset<21> usedNumbers = 0; // Tracks which numbers are used (max n = 20)
    vector<int> sequence; // Stores the final sequence
    
    // Recursive function to build the sequence using DFS
    bool dfs(int index) {
        if (index == seqLength) 
            return usedNumbers.count() == maxNum;  // Base case: all numbers are used
        
        if (sequence[index] != 0) 
            return dfs(index + 1);  // Skip filled positions

        // Try placing the largest unused number first for lexicographically largest sequence
        for (int num = maxNum; num >= 1; num--) {  
            if (usedNumbers[num]) continue;  // Skip if already placed
            
            int nextIndex = (num > 1) ? index + num : index;  // Find second occurrence
            
            // Ensure nextIndex is within bounds and empty
            if (nextIndex >= seqLength || sequence[nextIndex] != 0) continue;  

            // Place `num` at `index` and `nextIndex`
            sequence[index] = sequence[nextIndex] = num;
            usedNumbers[num] = 1;

            if (dfs(index + 1)) return true;  // Recurse

            // Backtrack if the choice was incorrect
            sequence[index] = sequence[nextIndex] = 0;
            usedNumbers[num] = 0;
        }
        return false;  // No valid placement found
    }

    vector<int> constructDistancedSequence(int n) {
        maxNum = n;
        seqLength = 2 * n - 1; // Total length of the sequence
        sequence.assign(seqLength, 0); // Initialize with zeros
        
        dfs(0); // Start the recursive DFS
        
        return sequence;
    }
};

/*

n=5
0 1 2 3 4 5 6 7 8 
5 4 3 2 1 5 4 3 2 
5 4 3 1 3 4 5 2 2 

5 3 1 4 3 5 2 4 2

5 3 1 4 3 5 2 4 2
0 1 2 3 4 5 6 7 8
5 3 4 1 3 5 4 2 2 X
5 3 1 4 3 5 2 4 2


n=6
0 1 2 3 4 5 6 7 8  9 10 
6 4 1 5 3 4 6 3 5  2  2    

*/