/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }



        Node* cur_head = new Node(head->val);
        Node* ret = cur_head;
        Node* old_head = head;

        // cout << "head: " << head << endl;
        // cout << "old_head: " << old_head << endl;
        // cout << "cur_head: " << cur_head << endl;
        // cout << "ret: " << ret << endl;

        while(head->next != nullptr) {
            Node* temp_next = new Node(head->next->val);
            cur_head->next = temp_next;
            cur_head = temp_next;
            head = head->next;

        }

        cur_head = ret;
        while(cur_head!= nullptr) {
            // cout << "node: " << cur_head->val << "addr: " << cur_head << endl;
            cur_head = cur_head->next;
        }
        head = old_head;
        cur_head = ret;

        head = old_head;
        cur_head = ret;
        
        while(cur_head!= nullptr) {
            if (head->random == nullptr) {
                cur_head->random == nullptr;
            }
            else {
                Node* newrand = ret;
                Node* temp = old_head;
                while(head->random!=temp) {
                    temp = temp->next;
                    newrand = newrand->next;
                }
                cur_head->random = newrand;
            }
            // cout << "node: " << cur_head->val << "random: " << cur_head->random << endl;
            cur_head = cur_head->next;
            head = head->next;
        }
        return ret;
    }
};