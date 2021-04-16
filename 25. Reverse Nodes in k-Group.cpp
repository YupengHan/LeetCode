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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while(prev != nullptr) {
            prev = reverseNextKNodes(prev, k);
        }
        return dummy->next;
    }

private:
    ListNode* reverseNextKNodes(ListNode* dummy, int k) {
        
        ListNode *cur = dummy;
        ListNode *n1 = cur->next;
        for (int i = 0; i < k; ++i) {
            cur = cur->next;
            if (cur == nullptr) return nullptr;
        }

        // dummy, n1, ..., nk, nkPlus
        ListNode *nk = cur;

        ListNode *nkPlus = cur->next;

        // dummy, n1, ..., nk, nkPlus
        // Prev , cur
        ListNode *prev = dummy;
        cur = n1;
        ListNode *nxt;
        for (int i = 0; i < k; ++i) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        n1->next = nkPlus;
        dummy->next = nk;
        return n1;


    }
};