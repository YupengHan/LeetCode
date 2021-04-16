/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> pList;
        while(p != nullptr) {
            pList.insert(p);
            p = p->parent;
        }

        while(q) {
            if (pList.find(q) != pList.end()) {
                return q;
            }
            q = q->parent;
        }
        return q;
    
    }
};