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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode();
        ListNode* temp = root;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto& node : lists)
            if(node != nullptr)
                pq.push(node);
        while (!pq.empty()) {
            ListNode* node = pq.top();
            temp->next = node;
            temp = node;
            pq.pop();
            if (node->next) {
                node = node->next;
                pq.push(node);
            }
        }
        return root->next;
    }

private:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // min-heap
        }
    };
};