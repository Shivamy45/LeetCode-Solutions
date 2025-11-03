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
        unordered_map<ListNode*, int> mpp;
        ListNode *t1 = headA, *t2 = headB;
        while (t1 != nullptr) {
            mpp[t1] = 1;
            t1 = t1->next;
        }
        while (t2 != nullptr) {
            if (mpp.find(t2) != mpp.end())
                return t2;
            t2 = t2->next;
        }
        return nullptr;
    }
};