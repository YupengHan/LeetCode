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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int levelNum = 0;
        while(!myQueue.empty()) {
            if (levelNum % 2 == 0) {
                // cout << "levelNum: " << levelNum << endl;
                levelNum++;
                vector<int> level;
                int levelSize = myQueue.size();
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* curNode = myQueue.front();
                    myQueue.pop();
                    level.push_back(curNode->val);
                    // cout << curNode->val << " ";
                    if (curNode->left != nullptr) {
                        myQueue.push(curNode->left);
                    }
                    if (curNode->right != nullptr) {
                        myQueue.push(curNode->right);
                    }
                    
                }
                // cout << endl;
                ret.push_back(level);
                // cout << "levelNum: " << levelNum << "toret" << endl;
                // flip = - flip;
            }
            else {
                // cout << "levelNum: " << levelNum << endl;
                levelNum++;
                vector<int> level;
                int levelSize = myQueue.size();
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* curNode = myQueue.front();
                    myQueue.pop();
                    level.insert(level.begin(), curNode->val);
                    // cout << curNode->val << " ";
                    if (curNode->left != nullptr) {
                        myQueue.push(curNode->left);
                    }
                    if (curNode->right != nullptr) {
                        myQueue.push(curNode->right);
                    }
                    
                }
                // cout << endl;
                ret.push_back(level);
                // for (auto n : level) {
                //     cout << n << endl;
                // }
                // cout << "levelNum: " << levelNum << "toret"<< endl;
                // flip = - flip;
            }
        }
        // ret.erase(ret.end());
        return ret;

    }
};