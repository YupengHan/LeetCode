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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> ret;

        if (root == nullptr) return ret;
        // myStack.push(root);
        TreeNode* curNode = root;
        while(curNode != nullptr || !myStack.empty()) {
            //极限左走
            while(curNode != nullptr) {
                myStack.push(curNode);
                curNode = curNode->left;
            }

            //左边没路了
            curNode = myStack.top();
            myStack.pop();
            ret.push_back(curNode->val);
            curNode = curNode->right;
        }
        return ret;
    }
};