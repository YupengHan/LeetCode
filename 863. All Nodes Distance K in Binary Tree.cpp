// class Solution {
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         unordered_map<int, vector<int>> adj;

//         queue<TreeNode*> myQueue;
//         myQueue.push(root);
//         while(!myQueue.empty()) {
//             TreeNode* cNode = myQueue.front();
//             myQueue.pop();
//             if (cNode->left) {
//                 adj[cNode->val].push_back(cNode->left->val);
//                 adj[cNode->left->val].push_back(cNode->val);
//                 myQueue.push(cNode->left);
//             }
//             if (cNode->right) {
//                 adj[cNode->val].push_back(cNode->right->val);
//                 adj[cNode->right->val].push_back(cNode->val);
//                 myQueue.push(cNode->right);
//             }
//         }


//         queue<int> myQ;
//         int level = 0;
//         myQ.push(target->val);
//         unordered_set<int> visited;
//         visited.insert(target->val);
//         while(level != K) {
//             level++;
//             int cSize = myQ.size();
//             for (int i = 0; i < cSize; ++i) {
//                 int cNode = myQ.front();
//                 myQ.pop();
//                 for (auto to : adj[cNode])  {
//                     if (!visited.count(to)) {
//                         myQ.push(to);    
//                         visited.insert(to);
//                     }
                    
//                 }    
//             }
            
//         }
//         vector<int> ret;
//         while(!myQ.empty()) {
//             int v = myQ.front();
//             myQ.pop();
//             ret.push_back(v);
//         }
//         return ret;
        


//     }
// };




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // if (root == nullptr) return -1;
        ans.clear();
        dis(root, target, K);
        return ans;
    }
private:
    vector<int> ans;

    int dis(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr) return -1;
        if (root == target) {
            collect(target, K); //leave nodes collect；
            return 0;
        }

        int l = dis(root->left, target, K);
        int r = dis(root->right, target, K);

        if (l >= 0) {
            if (l == K-1) ans.push_back(root->val);
            collect(root->right, K-l-2);
            return l+1;
        }
        if (r >= 0) {
            if (r == K-1) ans.push_back(root->val);
            collect(root->right, K-r-2);
            return r+1;
        }
        return -1;
    }

    void collect(TreeNode* root, int d) {
        if (root == nullptr || d < 0) return;
        if (d == 0) ans.push_back(root->val);
        collect(root->left, d-1);
        collect(root->right, d-1);
    }
};



















