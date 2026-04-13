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
    int helperMaxPathSum(TreeNode* root, int& maxSum) {
        if (!root)
            return 0;
        int left = helperMaxPathSum(root->left, maxSum);
        int right = helperMaxPathSum(root->right, maxSum);
        int maxNow = root->val + max({left, right, left + right, 0});
        maxSum = max(maxSum, maxNow);
        return root->val + max({left, right, 0});;
    }
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int maxSum = INT_MIN;
        int left = helperMaxPathSum(root->left, maxSum);
        int right = helperMaxPathSum(root->right, maxSum);
        maxSum = max(maxSum, root->val + max({left, right, left + right, 0}));
        return maxSum;
    }
};