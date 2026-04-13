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
        int left = max(0, helperMaxPathSum(root->left, maxSum));
        int right = max(0, helperMaxPathSum(root->right, maxSum));
        int maxNow = root->val + left + right;
        maxSum = max(maxSum, maxNow);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helperMaxPathSum(root, maxSum);
        return maxSum;
    }
};