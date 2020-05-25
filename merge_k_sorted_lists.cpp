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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) {
            return nullptr;
        }
        if (len == 1) {
            return lists[0];
        }

        // Note: This method takes too much time
        // ListNode* ret = nullptr;
        // for (int i = 0; i < len; i++) {
        //     ret = merge_two(ret, lists[i]);
        // }
        // return ret;

        while (lists.size() != 1) {
            int k = lists.size()/2;
            // cout << k << " " << lists.size() << endl;
            for (size_t i = 0; i < k; i++) { // 2*(k-1) 个
                lists[i] = merge_two(lists[i*2], lists[i*2+1]);
            }
            if (2*k < lists.size()) {
                lists[k] = lists[lists.size()-1];
                lists.erase(lists.begin()+k+1, lists.end());
            }
            else {
                lists.erase(lists.begin()+k, lists.end());    
            }
            
        }



        
        return lists[0];

    }

    ListNode* merge_two(ListNode* first, ListNode* second) {
        if (first == nullptr) {
            return second;
        }
        if (second == nullptr) {
            return first;
        }
        
        

        ListNode* pred_ret = new ListNode(-1);
        ListNode* cur_node = pred_ret;
        while (first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                ListNode* temp_node = new ListNode(first->val);
                cur_node -> next = temp_node;
                cur_node = cur_node->next;

                first = first->next;
            }
            else {
                ListNode* temp_node = new ListNode(second->val);
                cur_node -> next = temp_node;
                cur_node = cur_node->next;

                second = second->next;
            }
        }

        // here one of the listnode is end
        if (first == nullptr) first = second;
        while (first!=nullptr) {
            ListNode* temp_node = new ListNode(first->val);
            cur_node -> next = temp_node;
            cur_node = cur_node->next;

            first = first->next;
        }

        return pred_ret->next;
    }
};