/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ResultType {
public:
    bool a_exist, b_exist;
    TreeNode* lca;
    ResultType(bool a_exist, bool b_exist, TreeNode* lca) {
        this->a_exist = a_exist;
        this->b_exist = b_exist;
        this->lca = lca;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ResultType ret = helper(root, p, q);
        if (ret.a_exist && ret.b_exist) {
            return ret.lca;
        }
        else {
            return nullptr;
        }
    }

    ResultType helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return ResultType(false, false, nullptr);
        }
        ResultType left = helper(root->left, p, q);
        ResultType right = helper(root->right, p, q);
        if (left.a_exist && left.b_exist) {
            return ResultType(true, true, left.lca);
        }
        if (right.a_exist && right.b_exist) {
            return ResultType(true, true, right.lca);
        }
        if (right.a_exist && left.b_exist) {
            return ResultType(true, true, root);
        }
        if (right.b_exist && left.a_exist) {
            return ResultType(true, true, root);
        }

        if ((right.a_exist || left.a_exist) && root == q) {
            return ResultType(true, true, root);
        }
        if ((right.b_exist || left.b_exist) && root == p) {
            return ResultType(true, true, root);
        }
        bool cur_a_exist = left.a_exist || right.a_exist || root == p;
        bool cur_b_exist = left.b_exist || right.b_exist || root == q;
        return  ResultType(cur_a_exist, cur_b_exist, nullptr);

    }
};




























