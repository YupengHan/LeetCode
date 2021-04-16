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
class ReturnType {
public:
    ListNode* returnHead;
    ListNode* returnTail;
    ListNode* returnNext;

    ReturnType(ListNode* _returnHead, ListNode* _returnTail, ListNode* _returnNext) {
        this->returnHead = _returnHead;
        this->returnTail = _returnTail;
        this->returnNext = _returnNext;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *prev = dummy, *cur;
        dummy->next = head;
        
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        cur = prev->next;
        cout << prev->val << " " << cur->val << endl;
        ReturnType retList = reverseListNode(prev, cur, right-left);

        // ListNode* listHead = retList->returnHead;
        // ListNode* listTail = retList->returnTail;
        // ListNode* listNext = retList->returnNext;

        // prev->next = listHead;


        // for (int i = 0; i < right-left; i++) {
        //     ListNode* nxt = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = nxt;
            
        // }
        
        return dummy->next;
    }
private:
    ReturnType reverseListNode(ListNode* prevList, ListNode* head, int len) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *nxt;
        for (int i = 0; i <= len; ++i) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head->next = cur;
        prevList->next = prev;
        return ReturnType(prev, head, cur);
    }
};


















