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
        bool isBST;
        Data() {
            subtreeSum = 0;
            mx = INT_MIN;
            mn = INT_MAX;
            isBST = true;
        }
    };

    Data* validBST(TreeNode* root, int& ans) {
        // empty node
        if (!root)
            return new Data();
        auto left = validBST(root->left, ans);
        auto right = validBST(root->right, ans);
        Data* temp = new Data();
        if (left->isBST && right->isBST && left->mx < root->val &&
            root->val < right->mn) {
            temp->subtreeSum = left->subtreeSum + right->subtreeSum + root->val;
            ans = max(ans, temp->subtreeSum);
            temp->mx = max(root->val, right->mx);
            temp->mn = min(root->val, left->mn);
            return temp;
        }
        temp->isBST = false;
        return temp;
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        validBST(root, ans);
        return ans;
    }
};