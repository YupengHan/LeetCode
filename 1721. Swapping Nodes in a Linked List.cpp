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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = ListNode(0);
        dummy->next = head;





        int len = 0;
        ListNode *cur = head;
        while(cur != nullptr) {
            cur = cur->next;
            len++;
        }
        int node2Dist = len - (k-1);
        int node1Dist = k;

        ListNode *n1 = dummy;
        for (int i = 0; i < node1Dist; ++i) {
            n1 = n1->next;
        }

        for (int i = 0; i < node2Dist; ++i) {
            n2 = n2->next;
        }

        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;


        return dummy->next;


    }
};














