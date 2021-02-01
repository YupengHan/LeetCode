/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<string> ret;
    void expand(TreeNode* cnode, string cur) {
        if (cnode->left == nullptr && cnode->right  == nullptr) {
            ret.push_back(cur);
        }
        if (cnode->left != nullptr) {
            TreeNode* ncnode = cnode->left;
            string ncur = cur + "->" + to_string(ncnode->val);
            expand(ncnode, ncur);
        }
        if (cnode->right != nullptr) {
            TreeNode* ncnode = cnode->right;
            string ncur = cur + "->" + to_string(ncnode->val);
            expand(ncnode, ncur);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        string cur = "";
        cur += to_string(root->val);
        // cout << cur << endl;
        expand(root, cur);
        return ret;

    }
};