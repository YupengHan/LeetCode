/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        
        ListNode *f = head->next;
        
        ListNode *s = head;
        while(s!=f) {
            
            if (f->next == nullptr || f->next->next == nullptr) return false;
            f = f->next->next;
            s = s->next;
                
            
        }
        return true;


    }
};