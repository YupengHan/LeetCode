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
class ResultType {
public:
    bool is_bst;
    int tree_max, tree_min;
    ResultType (bool is_bst, int tree_max, int tree_min) {
        this->is_bst = is_bst;
        this->tree_max = tree_max;
        this->tree_min = tree_min;
    }
};



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ResultType ret = helper(root);
        return ret.is_bst;
        // if (root == nullptr) return true;
        // if (root->left == nullptr && root->right == nullptr) {
        //     return true;
        // }

        // if (root->left && root->left->val >= root->val) return false;
        // if (root->right && root->right->val <= root->val) return false;

        // return (isValidBST(root->left) && isValidBST(root->right));
    }
    ResultType helper(TreeNode* root) {
        if (root == nullptr) {
            return ResultType(true, INT_MIN, INT_MAX);
        }
        if (root->right == nullptr && root->left == nullptr) {
            return ResultType(true, root->val, root->val);
        }

        ResultType left_node = helper(root->left);
        ResultType right_node = helper(root->right);
        if (!left_node.is_bst || !right_node.is_bst) {
            return ResultType(false, 0, 0);
        }



        if (root->left && left_node.tree_max >= root->val) {
            return ResultType(false, 0, 0);
        }
        if (root->right && right_node.tree_min <= root->val) {
            return ResultType(false, 0, 0);
        }
        int cur_max = (right_node.tree_max > root->val) ? right_node.tree_max : root->val;
        int cur_min = (left_node.tree_min < root->val) ? left_node.tree_min : root->val;
        return ResultType(true, cur_max, cur_min);
    }
} ;











