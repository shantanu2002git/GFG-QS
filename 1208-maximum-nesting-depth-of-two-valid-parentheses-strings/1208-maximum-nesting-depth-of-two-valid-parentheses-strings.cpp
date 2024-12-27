class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int n = seq.length();          // Step 1: Get the length of the input string
        vector<int> answer(n);        // Step 1: Initialize the answer array
        int depth = 0;                 // Step 1: Initialize the depth variable

        // Step 2: Iterate through each character in the string
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {       // If the character is an opening parenthesis
                depth++;                // Increase the depth
                // Assign to A (0) if depth is odd, else assign to B (1)
                answer[i] = (depth % 2 == 1) ? 0 : 1;
            } else {                   // If the character is a closing parenthesis
                // Assign to A (0) if depth is odd, else assign to B (1)
                answer[i] = (depth % 2 == 1) ? 0 : 1;
                depth--;               // Decrease the depth
            }
        }

        return answer;                // Step 3: Return the answer array
       
    }
};