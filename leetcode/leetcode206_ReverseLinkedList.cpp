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
    ListNode* reverseList(ListNode* head) {
        // Edge case: if the list is empty or has only one node
        if (head == NULL || head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;  // Store the next node
            curr->next = prev;  // Reverse the current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = next;
        }
        return prev;  // prev will be the new head of the reversed list
    }
};