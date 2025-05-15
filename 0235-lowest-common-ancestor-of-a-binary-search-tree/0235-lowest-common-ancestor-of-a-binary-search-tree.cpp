/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* call(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }

        int rootval = root->val;
        if (rootval > p->val && rootval > q->val) {
            return call(root->left, p, q);
        }
        if (rootval < p->val && rootval < q->val) {
            return call(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return call(root, p, q);
    }
};