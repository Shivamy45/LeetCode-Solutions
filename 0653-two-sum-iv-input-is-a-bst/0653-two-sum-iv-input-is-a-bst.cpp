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
class Solution {
public:
    bool search(TreeNode* root, TreeNode* curr, int key) {
        if (!root)
            return false;
        if (root->val == key && root != curr)
            return true;
        else if (root->val < key)
            return search(root->right, curr, key);
        else if (root->val > key)
            return search(root->left, curr, key);
        return false;
    }
    bool traverse(TreeNode* root, TreeNode* curr, int k) {
        if (!curr)
            return false;
        int key = k - curr->val;
        if (search(root, curr, key))
            return true;
        return traverse(root, curr->left, k) || traverse(root, curr->right, k);
    }
    bool findTarget(TreeNode* root, int k) { return traverse(root, root, k); }
};