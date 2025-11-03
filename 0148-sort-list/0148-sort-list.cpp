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
    ListNode* helperMergeList(ListNode* temp1, ListNode* temp2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
            if(temp1 == nullptr){
                temp->next = temp2;
            } else if(temp2 == nullptr){
                temp->next = temp1;
            }
        }
        return dummyHead->next;
    }

    ListNode* helperMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = helperMiddle(head);
        ListNode *left = head, *right = middle->next;
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return helperMergeList(left, right);
    }
};