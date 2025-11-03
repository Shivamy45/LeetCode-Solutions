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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *t1 = headA, *t2 = headB;
        int n = 0, m = 0;
        while (t1) {
            m++;
            t1 = t1->next;
        }
        while (t2) {
            n++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        for (int i = 0; i < abs(m - n); i++)
            if (m > n)
                t1 = t1->next;
            else
                t2 = t2->next;
        while (t1 != nullptr && t2 != nullptr) {
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
};