/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root;
        while(curr){
            Node *c2 = curr;
            while(c2){
                if(c2->left){
                    c2->left->next = c2->right;
                    c2->right->next = (c2->next) ? c2->next->left : nullptr;
                }
                c2 = c2->next;
            }
            curr = curr->left;
        }   
        return root;
    }
};