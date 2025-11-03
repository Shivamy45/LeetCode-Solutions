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
    ListNode* helperMergeList(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        ListNode *temp1 = head1, *temp2 = head2;
        int value;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val < temp2->val) {
                value = temp1->val;
                temp1 = temp1->next;
            } else {
                value = temp2->val;
                temp2 = temp2->next;
            }
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = newNode;
        }
        while (temp1 != nullptr) {
            value = temp1->val;
            temp1 = temp1->next;
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = newNode;
        }
        while (temp2 != nullptr) {
            value = temp2->val;
            temp2 = temp2->next;
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = newNode;
        }
        return dummyHead->next;
    }

    ListNode* helperMiddle(ListNode* head) {
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