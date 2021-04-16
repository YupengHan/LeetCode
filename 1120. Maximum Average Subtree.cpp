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
class ReturnType {
public:
    int sum;
    int num;
    // float avg;
    ReturnType(int sum, int num) {
        this->sum = sum;
        this->num = num;
        // if (num != 0) {
        //     this->avg = (sum + 0.0)/num;
        // }
        // else {
        //     this->avg = 0;
        // }
    }
};

class Solution {
private:
    double maxAvg;
public:
    double maximumAverageSubtree(TreeNode* root) {
        maxAvg = 0;
        helper(root);
        return maxAvg;
    }

    ReturnType helper(TreeNode* root) {
        if (root == nullptr) {
            return ReturnType(0, 0);
        }

        ReturnType left = helper(root->left);
        ReturnType right = helper(root->right);
        double curAvg = (left.sum + right.sum + root->val + 0.0) / (left.num + right.num + 1);
        // cout << curAvg << endl;
        // maxAvg = maxAvg > curAvg ? maxAvg : curAvg;
        // cout << maxAvg << endl;
        if (curAvg > maxAvg) {
            
            // maxAvg = curAvg;
            
            // cout << maxAvg << " " << curAvg << endl;
            maxAvg = curAvg;
            // cout << "after mod: " << maxAvg << " " << curAvg << endl;
        }
        return ReturnType(left.sum + right.sum + root->val, left.num + right.num + 1);
    }
};


















