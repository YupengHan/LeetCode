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
        int dep = find_depth(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> d = decode(data);
        int len = d.size();
        Vector<TreeNode*> vt(len);
        for (int i = 0; i < len; i++) {
            vt[i] = TreeNode()
        }
        
    }
private:
    stack<TreeNode*> tp;
    vector<int> decode(string s) {
        vector<int> ret;
        s = s.substr(1, s.size()-2);
        stringstream cs(s);
        string im;
        while(getline(cs, im, ',')) {
            stringstream imint(im);
            int tmp;
            imint >> tmp;
            ret.push_back(tmp);
        }
        return ret;
        
    }
    int find_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(1+find_depth(root->left), 1+find_depth(root->right));

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));