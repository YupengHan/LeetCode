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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        stack<pair<TreeNode*, string>> myStack;
        myStack.push(make_pair(root, to_string(root->val)));

        if (root == nullptr) return ret;

        while(!myStack.empty()) {
            pair<TreeNode*, string> curPair;
            curPair = myStack.top();
            myStack.pop();
            TreeNode* curNode = curPair.first;
            string curStr = curPair.second;
            if (curNode == nullptr) {
                cout << curStr << endl;
            }
            
            if (curNode->left == nullptr && curNode->right == nullptr) {
                ret.push_back(curStr);
                cout << curStr << endl;
            }
            if (curNode->right != nullptr) {
                string rightStr = curStr + "->" + to_string(curNode->right->val);
                myStack.push(make_pair(curNode->left, rightStr));
            }
            if (curNode->left != nullptr) {
                string leftStr = curStr + "->" + to_string(curNode->left->val);
                myStack.push(make_pair(curNode->left, leftStr));
            }

        }
        return ret;
    }
};