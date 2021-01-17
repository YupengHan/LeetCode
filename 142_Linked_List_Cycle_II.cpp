/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Hash Table
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> node_set;
        ListNode *mynodeptr = head;
        while (mynodeptr != nullptr) {
            if (node_set.count(mynodeptr) == 0) {
                node_set.emplace(mynodeptr);
                mynodeptr = mynodeptr->next;

            }
            else {
                return mynodeptr;
            }
            
        }
        return nullptr;
    }
};

// 

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
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        do {
            if(!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;

        }while (fast != slow)

        fast = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

        
    }
};
