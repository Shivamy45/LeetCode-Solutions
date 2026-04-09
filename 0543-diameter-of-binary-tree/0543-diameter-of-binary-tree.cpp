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
    int diameter = 0;
    int helperDiameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = helperDiameterOfBinaryTree(root->left);
        int right = helperDiameterOfBinaryTree(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        helperDiameterOfBinaryTree(root);
        return diameter;
    }
};