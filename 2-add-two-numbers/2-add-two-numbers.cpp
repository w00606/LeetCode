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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum_head = NULL;
        ListNode** sum = &sum_head;
        int digit_sum = 0;
        while (true) {
            if (l1 != NULL) {
                digit_sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                digit_sum += l2->val;
                l2 = l2->next;
            }
            *sum = new ListNode(digit_sum % 10);
            sum = &(*sum)->next;
            digit_sum /= 10;
            if (l1 == NULL && l2 == NULL) {
                if (digit_sum != 0) {
                    *sum = new ListNode(digit_sum);
                    sum = &(*sum)->next;
                }
                break;
            }
        }
        return sum_head;
    }
};