/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // if (fast->next == nullptr || fast->next->next == nullptr) {
        //     return slow;
        // }
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            // printf("fast : %d.  slow: %d\n", fast->val, slow->val);
        }
        // if ()
        return fast->next ? slow->next : slow;
    }
};