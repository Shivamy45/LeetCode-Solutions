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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int sum = 0, carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = newNode;
        }

        return head->next;
    }
};