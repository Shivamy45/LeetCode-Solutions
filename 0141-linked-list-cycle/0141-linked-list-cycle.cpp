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
    bool hasCycle(ListNode* head) {
        // this code just tells the presence of cycle not the entry point of
        // cycle

        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != NULL and fast != NULL and fast->next != NULL) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};