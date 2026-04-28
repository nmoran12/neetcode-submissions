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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        ListNode* curr = head;
        int n = 0;
        int i = 0;



        int currLargest = 0;

        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse linked list
        while (slow != nullptr){
            next = slow->next;
            slow->next = prev;

            prev = slow;
            slow = next;
        };

        while (prev != nullptr && head != nullptr){
            if ((prev->val + head->val) > currLargest){
                currLargest = prev->val + head->val;
            }

            prev = prev->next;
            head = head->next;
        }

        return currLargest;
    }
};