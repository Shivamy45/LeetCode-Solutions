/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helperInorderTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    helperInorderTraversal(root->left, res);
    res.push_back(root->val);
    helperInorderTraversal(root->right, res);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    helperInorderTraversal(root, res);
    return res;
}
};