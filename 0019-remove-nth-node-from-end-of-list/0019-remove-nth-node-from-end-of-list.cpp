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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            size++;
            temp = temp->next;
        }
        temp = head;
        if (n == size)
            return head->next;
        for (int i = 0; i < size - n - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};