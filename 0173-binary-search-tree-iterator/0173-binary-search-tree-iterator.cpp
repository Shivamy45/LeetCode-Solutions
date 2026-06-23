/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> antiBST;
    BSTIterator(TreeNode* root) {
        antiInorder(root);
        antiBST.push(new TreeNode(-1));
    }
    void antiInorder(TreeNode* root) {
        if (!root)
            return;
        antiInorder(root->right);
        antiBST.push(root);
        antiInorder(root->left);
    }

    int next() {
        antiBST.pop();
        return antiBST.top()->val;
    }

    bool hasNext() { return antiBST.size() > 1; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */