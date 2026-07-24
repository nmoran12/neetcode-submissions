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
        ListNode dummy(0);
        ListNode* curr = dummy&;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = 0;

            if (l1 != nullptr){
                sum += l1->val;
                l1->next;
            }

            if (l2 != nullptr){
                sum += l2->val;
                l2->next;
            }

            int resultDigit = sum % 10;
            int carryDigit = sum / 10;

            sum += carry;
        }
        
    }
};
