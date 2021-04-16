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
   vector<TreeNode *> m;
    void dfs(TreeNode *root){
        if(root==NULL) return;
        m.push_back(root); 
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        for(int i=1;i<m.size();i++){
            m[i-1]->left=NULL;
            m[i-1]->right=m[i];
        }
    }
};