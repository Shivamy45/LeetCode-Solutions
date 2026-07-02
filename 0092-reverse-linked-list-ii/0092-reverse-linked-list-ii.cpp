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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prevNode = dummy;
        for(int i = 1; i < left; i++) prevNode = prevNode->next;
        ListNode *curr = prevNode->next;
        ListNode *prev = nullptr, *next = curr->next;
        for(int i = left; i<= right; i++){
            // reverse code
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next)
            next = next->next;
        }
        // joining the reverse part
        prevNode->next->next = curr;
        prevNode->next = prev;
        return dummy->next;
    }
};