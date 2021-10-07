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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* nnhead = head;
        ListNode prevNode;
        ListNode* prev = &(prevNode);
        prev->next = head;
        ListNode* ret = prev;
        for (int i = 0; i < n-1; ++i) {
            nnhead = nnhead->next;
        }
        while(nnhead->next != nullptr) {
            nnhead = nnhead->next;
            head = head->next;
            prev = prev->next;
        }
        prev->next = head->next;
        return ret->next;
    }
};