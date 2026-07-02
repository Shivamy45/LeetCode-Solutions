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
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *temp = head, *prev = end, *next = head->next;
        while (temp != end) {
            temp->next = prev;
            prev = temp;
            temp = next;
            if (next)
                next = next->next;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode *end = head, *temp = dummyHead;
        for (int i = 1; i <= right; i++)
            end = end->next;
        for (int i = 1; i < left; i++)
            temp = temp->next;
        temp->next = reverse(temp->next, end);
        return dummyHead->next;
    }
};