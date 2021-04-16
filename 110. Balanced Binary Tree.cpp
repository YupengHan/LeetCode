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
class ReturnType {
public:
    bool isBalanced;
    int maxDepth;
    ReturnType(bool isBalanced, int maxDepth) {
        this->isBalanced = isBalanced;
        this->maxDepth = maxDepth;
    }
};


class Solution {

public:
    bool isBalanced(TreeNode* root) {
        return helper(root).isBalanced;
    }

    ReturnType helper(TreeNode* root) {
        if (root == nullptr) return ReturnType(true, 0);
        ReturnType left = helper(root->left);
        ReturnType right = helper(root->right);

        if (!left.isBalanced || !right.isBalanced) {
            return ReturnType(false, -1);
        }

        if (abs(left.maxDepth - right.maxDepth) > 1) {
            return ReturnType(false, -1);
        }

        return ReturnType(true, max(left.maxDepth, right.maxDepth)+1);
    }

    

};


















