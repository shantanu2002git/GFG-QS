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
    void call(TreeNode* root, map<int, int>& mp, int lv) {
        if (root == NULL) {
            return;
        }
        mp[lv] = root->val;
        call(root->left,mp, lv + 1);
        call(root->right,mp, lv + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp; // lvl , node
        call(root, mp, 0);
        vector<int> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};