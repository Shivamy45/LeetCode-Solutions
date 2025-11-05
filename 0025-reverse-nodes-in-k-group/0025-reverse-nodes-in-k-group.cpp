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
    ListNode* helperReverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = nullptr, *temp = head, *nextNode = head->next;
        while (temp) {
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            if (nextNode)
                nextNode = nextNode->next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* lastNode = temp;
        while (temp) {
            ListNode* kthNode = temp;
            int end = k - 1;
            while (kthNode && end--)
                kthNode = kthNode->next;
            if (!kthNode) {
                lastNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            kthNode = helperReverse(temp);
            if (temp == head)
                head = kthNode;
            else {
                lastNode->next = kthNode;
                lastNode = temp;
            }
            temp = nextNode;
        }
        return head;
    }
};