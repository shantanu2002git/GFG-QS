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
    int deep(TreeNode* root, int h) {
        if (root == NULL) {
            return 0;
        }
        int lef =1+ deep(root->left, h + 1);
        int rig = 1+deep(root->right, h + 1);
        return max(lef, rig);
    }
    int maxDepth(TreeNode* root) { return deep(root, 0); }
};