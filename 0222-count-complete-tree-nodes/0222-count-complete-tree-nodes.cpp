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
    int helperCountNode(TreeNode* root, bool left) {
        int h = 0;
        while (root) {
            h++;
            root = (left) ? root->left : root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftH = helperCountNode(root, true);
        int rightH = helperCountNode(root, false);
        if (leftH == rightH)
            return (1 << leftH) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};