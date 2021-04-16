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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* cur = head;
        int len = 0;
        while(cur != nullptr) {
            cur = cur->next;
            len++;
        }
        // cout << len << endl;
        k = k % len;

        for (int i = 0; i < k; ++i) {
            ListNode *tailMinus = head;
            while(tailMinus->next->next != nullptr) {
                tailMinus = tailMinus->next;
            }

            ListNode *tail = tailMinus->next;

            tail->next = head;
            tailMinus->next = nullptr;
            head = tail;

        }
        return head;


    }
};