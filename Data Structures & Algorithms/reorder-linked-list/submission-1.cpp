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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        // we start fast at head->next because it makes slow stop at end of first half of array, which is good.
        ListNode* fast = head->next;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;


        // Fast and Slow Pointers to find middle of linked list
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // This is the part that splits the list into two
        // 'slow' is the LAST ELEMENT OF THE FIRST ARRAY,
        // so if we want second to be the start of the second array, we must access the slow->next.
        ListNode* second = slow->next;
        // This part actually cuts the arrays in two, so we get
        // [2 -> 4 -> 6 -> nullptr] [8 -> 10 -> nullptr]
        slow->next = nullptr;


        // Reverses only second array
        ListNode* curr = second;

        // Reverse Linked List
        while (curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        ListNode* first = head;
        // Prev is now the head of our second array, so we set that to second
        second = prev;


        while (second != nullptr){

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            // Pattern of merging: first node -> second node -> temp1
            first->next = second;
            second->next = temp1;

            // Move first and second forward
            first = temp1;
            second = temp2;

        }
        
    }
};
