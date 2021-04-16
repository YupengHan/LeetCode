/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class ResultType {
public:
    Node* firstNode;
    Node* lastNode;
    ResultType (Node* _firstNode, Node* _lastNode) {
        this->firstNode = _firstNode;
        this->lastNode = _lastNode;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        ResultType ret = helper(root);
        ret.firstNode->left = ret.lastNode;
        ret.lastNode->right = ret.firstNode;
        return ret.firstNode;
    }
    ResultType helper(Node* root) {
        if (root == nullptr) {
            return ResultType(nullptr, nullptr);
        }

        if (root->left == nullptr && root->right == nullptr) {
            return ResultType(root, root);
        }

        if (root->left == nullptr) {
            ResultType right_list = helper(root->right);
            root->right = right_list.firstNode;
            right_list.firstNode->left = root;
            return ResultType(root, right_list.lastNode);
        }

        if (root->right == nullptr) {
            // cout << "21" << endl;
            ResultType left_list = helper(root->left);
            left_list.lastNode->right = root;
            root->left = left_list.lastNode;
            return ResultType(left_list.firstNode, root);
        }

        ResultType left_list = helper(root->left);
        ResultType right_list = helper(root->right);

        left_list.lastNode->right = root;
        root->left = left_list.lastNode;
        root->right = right_list.firstNode;
        right_list.firstNode->left = root;

        return ResultType(left_list.firstNode, right_list.lastNode);
    }
}; 

















