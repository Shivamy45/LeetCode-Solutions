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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr, *temp = head, *forward = head->next;
        while(temp != nullptr){
            temp->next = prev;
            prev = temp;
            temp = forward;
            if(forward != nullptr)
                forward = forward->next;
        }
        return prev;
    }
};