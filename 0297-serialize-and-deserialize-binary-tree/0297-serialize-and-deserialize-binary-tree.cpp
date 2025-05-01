/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "NULL";
        }

        return to_string(root->val) + "*" + serialize(root->left) + "*" +
               serialize(root->right); // preorder traversal
    }

    TreeNode* decodeasTree(queue<string>& q) {
        string nd = q.front();
        q.pop();
        if (nd == "NULL") {
            return NULL;
        }
        TreeNode* nwnd = new TreeNode(stoi(nd));
        nwnd->left = decodeasTree(q);
        nwnd->right = decodeasTree(q);

        return nwnd;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string store;
        cout << data << " ";
        queue<string> q;
        for (auto i : data) {
            if (i == '*') {
                q.push(store);
                store = "";
                continue;
            }

            store = store + i;
        }
        if (!store.empty()) {
            q.push(store);
        }
        queue<string> see;
        see = q;
        cout << endl;
        while (!see.empty()) {
            cout << see.front() << " ";
            see.pop();
        }
        return decodeasTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));