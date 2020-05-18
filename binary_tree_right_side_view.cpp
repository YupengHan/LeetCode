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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        
        TreeNode *cur_node = root;
        ret.insert(ret.end(), cur_node->val);
        cout << cur_node->val << endl;
        


        while (haschild(cur_node)) {
            if (cur_node->right != nullptr) {
                cur_node = cur_node->right;
                ret.insert(ret.end(), cur_node->val);
                cout << cur_node->val << endl;
            }
            else {
                cur_node = cur_node->left;
                ret.insert(ret.end(), cur_node->val);
                cout << cur_node->val << endl;
            }
        }
        return ret;
    }
    bool haschild(TreeNode * node){
        if (node->left == nullptr && node->right == nullptr) {
            return false;
        }
        else return true;
    }
};
// 根据地址的增长顺序，强行用数学解