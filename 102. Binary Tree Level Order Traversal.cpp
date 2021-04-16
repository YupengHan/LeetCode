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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        queue<TreeNode*> my_q;
        my_q.push(root);
        while(!my_q.empty()) {
            new vector<int> cur_level;
            int cnt = my_q.size();
            while(cnt) {
                cnt--;
                TreeNode* cur_node = my_q.front();
                my_q.pop();
                cur_level.push_back(cur_node->val);
                if (cur_node->left) {
                    my_q.push(cur_node->left);
                }
                if (cur_node->right) {
                    my_q.push(cur_node->right);
                }
            }
            ret.push_back(cur_level);

        }
        return ret;
    }
};