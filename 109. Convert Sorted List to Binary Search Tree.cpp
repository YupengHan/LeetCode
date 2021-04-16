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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *s = head;
        ListNode *f = head;
        while(f!=nullptr && f->next != nullptr) {
            prev = s;
            
            s = s->next;
            f = f->next->next;
        }
        if (prev != nullptr) prev->next = nullptr;
        return s;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr ) return nullptr;
        ListNode *mid = findMiddle(head);
        TreeNode* ret = new TreeNode(mid->val);

        if (head == mid) {
            return ret;
        }
        


        ret->right = sortedListToBST(mid->next);
        // mid->next = nullptr;
        
        ret->left = sortedListToBST(head);

        return ret;

    }
};