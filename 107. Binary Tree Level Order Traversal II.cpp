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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }

        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()) {
            vector<int> level;
            int level_size = my_queue.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* cur_node = my_queue.front();
                my_queue.pop();
                level.push_back(cur_node->val);
                if (cur_node->left != nullptr) {
                    my_queue.push(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    my_queue.push(cur_node->right);
                }
            }
            results.insert(results.begin(), level);
        }
        return results;

    }
};