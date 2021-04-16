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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        while(root!= nullptr) {
            // cout << root->val << endl;
            if (root->val == val) return root;
            if (root->val > val) {
                if (root->left == nullptr) return nullptr;
                root = root->left;
                
            }
            if (root->val < val) {
                if (root->right == nullptr) return nullptr;
                root = root->right;
            }
        }
        return nullptr;
    }
};