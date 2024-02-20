<h2><a href="https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1">String Subsequence</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings <strong>S1</strong> and <strong>S2</strong>, Count no. of all subsequences of string <strong>S1&nbsp;</strong>that are equal to string&nbsp;<strong>S2</strong>.</span></p>
<p><span style="font-size: 18px;"><span style="font-size: 18px;">Since answer can be huge return answer modulo <strong>1e9+7.</strong></span></span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
S1 = geeksforgeeks
S2 = gks
<strong>Output:</strong> 4
<strong>Explaination: </strong>We can pick characters from S1 as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}.So total 4 subsequences of S1 that are equal to S2.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>countWays()</strong> which takes the string S1 and S2 as input parameters and returns the number of desired subsequences.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n*m)&nbsp; &nbsp; &nbsp; &nbsp; [n and m are length of the strings]<br><strong>Expected Auxiliary Space:</strong> O(n*m)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 500</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;