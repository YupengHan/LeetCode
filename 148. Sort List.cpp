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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        if (head1) {
            tail ->next = head1;
        }
        if (head2) {
            tail ->next = head2;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *mid = findMiddle(head);
        ListNode *right = sortList(mid->next);
        mid->next = nullptr;
        ListNode *left = sortList(head);

        ListNode* ret = merge(left, right);
        return ret;
        
    }
};