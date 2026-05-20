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
    TreeNode *build(vector<int>&inorder, vector<int>&postorder, int &idx, int l, int r, unordered_map<int, int>&mpp){
        if(l > r) return nullptr;
        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);
        int i = mpp[val];
        root->right = build(inorder, postorder, idx, i + 1, r, mpp);
        root->left = build(inorder, postorder, idx, l, i - 1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        int idx = n - 1;
        return build(inorder, postorder, idx, 0, n - 1, mpp);
    }
};