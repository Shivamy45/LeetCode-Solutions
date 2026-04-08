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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }

    int helperDiameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int edgeL = maxDepth(root->left), edgeR = maxDepth(root->right);
        return max(edgeL + edgeR, max(helperDiameterOfBinaryTree(root->left),
                                      helperDiameterOfBinaryTree(root->right)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helperDiameterOfBinaryTree(root);
    }
};