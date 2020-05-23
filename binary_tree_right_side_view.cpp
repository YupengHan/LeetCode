
// 根据地址的增长顺序，强行用数学解 --> 这是错误解法

// Q how to loop over binary tree (without parent)
// A Using stack
/*
    1 create empty stack
    2 initialize current node as root
    3 push currrent node to S and set cur = cur->left until cur->left == nullptr
    4 if cur->left == nullptr
        a) pop top of stack
        b) set cur = poped_item->rihgt
        c) go to 3
    5 if cur == nullptr && stack is empty -> DONE
*/

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
        vector<int> ret_vector;
        if (root == nullptr) {
            return ret_vector;
        }
        // if (root->left == nullptr && root->right == nullptr) {
        //     ret_vector.insert(ret_vector.begin(),root->val);
        //     return ret_vector;
        // }
        
        

        int max_layer = -1;
        int cur_layer = 0;
        stack<pair<int, TreeNode*>> bt; //left, right
        // bt.push(make_pair(-1, root));
        // TreeNode *cur_node = root;

        
        while (root->left != nullptr || root->right != nullptr || root != nullptr || bt.size() > 0) {
            if (root->right != nullptr) {
                // cout << root->val << " " << cur_layer << " " << max_layer << " " << bt.size() << endl;
                if (root->left != nullptr) {
                    bt.push(make_pair(cur_layer, root));
                }
                if (cur_layer > max_layer) {
                    cout << "add!!" << endl;
                    max_layer++;
                    ret_vector.insert(ret_vector.end(), root->val);
                }
                root = root->right;
                cur_layer++;
                continue;
            }
            
            if (root->left != nullptr) { // right is empty
                // cout << root->val << " " << cur_layer << " " << max_layer << " " << bt.size() << endl;
                if (cur_layer > max_layer) {
                    max_layer++;
                    cout << "add!!" << endl;
                    ret_vector.insert(ret_vector.end(), root->val);
                }
                root = root->left;
                cur_layer++;
                continue;
            }

            // cout << root->val << " " << cur_layer << " " << max_layer << " " << bt.size() << endl;
            
            if (cur_layer > max_layer) {
                max_layer++;
                cout << "add!!" << endl;
                ret_vector.insert(ret_vector.end(), root->val);
            }
            
            if (bt.size() > 0) {
                pair <int, TreeNode*> temp;
                temp = bt.top();
                bt.pop();
                cur_layer = temp.first+1;
                root = temp.second->left;
            }
            else {
                break;
            }
            
            
        }
        return ret_vector;
    }
    
    
};