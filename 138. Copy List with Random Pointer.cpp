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
        if (head == nullptr) return head;
        Node* odd = head;
        Node* even;
        while(odd != nullptr) {
            even = new Node(odd->val);
            even->next = odd->next;
            odd->next = even;
            odd = odd->next->next;
        }
        
        odd = head;
        even = odd->next;

        while(odd != nullptr) {
            if (even && odd->random) {
                even->random = odd->random->next;
                
            }
            odd = odd->next->next;
            if (even->next) {
                even = even->next->next;    
            }
            
        }

        odd = head;
        even = odd->next;
        Node* ret = even;
        while(odd != nullptr) {
            odd  -> next = odd ->next->next;
            if (even -> next) {even -> next = even->next->next;}
            
            odd  = odd -> next;
            even = even-> next;
        }
        return ret;

    }
};