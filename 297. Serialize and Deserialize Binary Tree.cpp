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
    vector<string> split(string str, string token){
        vector<string>result;
        while(str.size()){
            int index = str.find(token);
            if(index!=string::npos){
                result.push_back(str.substr(0,index));
                str = str.substr(index+token.size());
                if(str.size()==0)result.push_back(str);
                }
                else {
                    result.push_back(str);
                    str = "";
                }
        }
        return result;
    }



    string rserialize(TreeNode* root, string str) {
        if (root == nullptr) {
            str += "null,";
        }
        else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
        return str;
    }
    string serialize(TreeNode* root) {
        return rserialize(root, "");
        
    }

    // Decodes your encoded data to tree.
    TreeNode* rdeserialize(vector<string> d) {
        if (d[0] == "null") {
            // d.pop_front();
            d.erase(d.begin());
            return nullptr; 
        }
        TreeNode* root = TreeNode(stoi(d[0]));
        root->left = rdeserialize(d);
        root->rihgt = rdeserialize(d);


    }
    TreeNode* deserialize(string data) {
        vector<string> d_v = split(data, ",");
        return rdeserialize(d_v)
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));