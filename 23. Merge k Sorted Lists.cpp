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
    struct cmp {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 ) return nullptr;
        for (auto l : lists) {

            ListNode* c = l;
            while(c != nullptr) {
                pq.push(c->val);
                c = c -> next;
            }

        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(!pq.empty()) {
            int cVal = pq.top();
            pq.pop();
            ListNode* cNode = new ListNode(cVal);
            cur->next = cNode;
            cur = cNode;
        }
        return dummy->next;
    }
};