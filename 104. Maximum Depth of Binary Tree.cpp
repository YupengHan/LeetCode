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
    int maxDepth(TreeNode* root) {
        int curMax = 0;
        stack<pair<TreeNode*, int>> myStack;
        if (root == nullptr) return 0;
        myStack.push(make_pair(root, 1));

        while(!myStack.empty()) {
            TreeNode* curNode;
            int curDepth;
            // curNode, curDepth = myStack.top(); //这个表达不对！！！
            pair<TreeNode*, int> myPair = myStack.top();
            curNode = myPair.first;
            curDepth = myPair.second;
            myStack.pop();
            if (curMax < curDepth) curMax = curDepth;

            if (curNode->left != nullptr) {
                myStack.push(make_pair(curNode->left, curDepth+1));
            }
            if (curNode->right != nullptr) {
                myStack.push(make_pair(curNode->right, curDepth+1));
            }
        }
        return curMax;
    }
};