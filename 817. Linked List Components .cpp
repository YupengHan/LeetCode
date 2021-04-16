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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> rel;
        ListNode* cur = head;
        while(cur->next != nullptr) {
            rel[cur->val] = cur->next->val;
            // cout << cur->val << " " << cur->next->val << endl;
            cur = cur->next;
            
        }
        
        unordered_set<int> ans;
        for (auto n : G) {
            ans.insert(n);
        }
        
        
        cur = head;
        while(cur->next != nullptr) {
            int cVal = cur->val;
            if (ans.count(cVal) && ans.count(rel[cVal])) {
                ans.erase(cVal);    
            }
            cur = cur->next;
        }
        return ans.size();
        
    }
};