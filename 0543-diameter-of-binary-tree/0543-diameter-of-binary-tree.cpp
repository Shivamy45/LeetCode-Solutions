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
    int helperDiameterOfBinaryTree(TreeNode* root, int& diameter) {
        if (root == nullptr)
            return 0;
        int left = helperDiameterOfBinaryTree(root->left, diameter);
        int right = helperDiameterOfBinaryTree(root->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int diameter = 0;
        helperDiameterOfBinaryTree(root, diameter);
        return diameter;
    }
};