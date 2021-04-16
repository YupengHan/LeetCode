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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> myStack;
        
        if (root == nullptr) return ret;
        myStack.push(curNode);

        while(!myStack.empty()) {
            TreeNode* curNode = myStack.top();
            myStack.pop();
            ret.insert(ret.begin(), curNode->val);
            if (curNode->left != nullptr) {
                myStack.push(curNode->left);
            }
            if (curNode->right != nullptr) {
                myStack.push(curNode->right);
            }
        }
        return ret;
    }
};