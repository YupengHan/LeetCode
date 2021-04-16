/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string ret;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        // ret = to_string(root->val) + " ";
        while(!myQueue.empty()) {
            TreeNode* curNode = myQueue.front();
            myQueue.pop();
            if (curNode == nullptr) {
                ret += "null ";
            }
            else {
                ret += to_string(curNode->val) + " ";
                myQueue.push(curNode->left);
                myQueue.push(curNode->right);
            }
        }
        // cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if (data.size() == 0) return nullptr;
        stringstream ss(data);
        string str;
        vector<string> strVec;
        while(ss >> str) {
            strVec.push_back(str);
        }

        int start = 0;
        int end = strVec.size();

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(strVec[start]));
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            int cldLeft = start + 1, cldRight = start + 2;
            if (strVec[cldLeft] != "null" && cldLeft < end) {
                curNode->left = new TreeNode(stoi(strVec[cldLeft]));
                q.push(curNode->left);
            }
            if (strVec[cldRight] != "null" && cldRight < end) {
                curNode->right = new TreeNode(stoi(strVec[cldRight]));
                q.push(curNode->right);
            }
            start += 2;
        }
        return root;



        // TreeNode* root;
        // return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));