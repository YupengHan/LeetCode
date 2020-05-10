/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode PreHead = ListNode(0);
        ListNode *nodePtr = &PreHead;
        int next_bit = 0;
        int sum;
        while(l1 || l2 || next_bit) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + next_bit;
            nodePtr->next = new ListNode((sum)%10); // 这里必须加new 
            /*
            写代码时突然想到for循环里面定义的变量的生存周期问题：
            for（int i=0; i<for_size; i++）
            {
                vartype temp;
                //do something
            }

            1.对于i--它是在for_size次for循环结束后才会释放内存,也就是说其作用域为整个for循环

            2.对于temp--它是在每一次for循环之后都会释放内存，然后第二次for循环的时候重新申请内存

            对于上面的验证：可以单步调试，然后看看temp和i的内存地址在每一次for循环的时候是否有变化

            如果有变化，则表示经过了释放重新申请过内存
            */
            next_bit = (sum)>9 ? 1 : 0;
            




            nodePtr = nodePtr->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return PreHead.next;
    }
};