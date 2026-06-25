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

    struct Data {
        int subtreeSum;
        int mx;
        int mn;
        Data(int a, int b, int c) : subtreeSum(a), mx(b), mn(c) {};
    };
    int ans = 0;

    Data* validBST(TreeNode* root) {
        // empty node
        if (!root)
            return new Data(0, INT_MIN, INT_MAX);
        auto left = validBST(root->left);
        auto right = validBST(root->right);
        int subtreeSum = left->subtreeSum + right->subtreeSum + root->val;
        if (left->mx < root->val && root->val < right->mn) {
            ans = max(ans, subtreeSum);
            return new Data(subtreeSum, max(right->mx, root->val),
                            min(left->mn, root->val));
        }
        return new Data(subtreeSum, INT_MAX, INT_MIN);
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        validBST(root);
        return ans;
    }
};