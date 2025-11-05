/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp) {
            temp->next = new Node(temp->val, temp->next);
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        Node* dummyHead = new Node(-1, head);
        Node* res = dummyHead;
        temp = head;
        while (temp) {
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummyHead->next;
    }
};