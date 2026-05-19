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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r,
                    int &idx, unordered_map<int, int>& mpp) {
        if (idx == preorder.size())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx]);
        int i = mpp[preorder[idx]];
        if (i - 1 > l){
            idx++;
            root->left = build(preorder, inorder, l, i, idx, mpp);
        }
        if (i + 1 < r){
            idx++;
            root->right = build(preorder, inorder, i, r, idx, mpp);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            mpp[inorder[i]] = i;
        int idx = 0;
        return build(preorder, inorder, -1, n, idx, mpp);
    }
};