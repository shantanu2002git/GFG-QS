/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDiameter = 0;

    int call(TreeNode* nd) {
        if (nd == NULL) {
            return 0;
        }
        int left = call(nd->left);
        int right = call(nd->right);
        maxDiameter = max(maxDiameter, left + right);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int left = call(root);
        // int right = call(root->right);
        cout << left << " " << right;
        return maxDiameter;
    }
};