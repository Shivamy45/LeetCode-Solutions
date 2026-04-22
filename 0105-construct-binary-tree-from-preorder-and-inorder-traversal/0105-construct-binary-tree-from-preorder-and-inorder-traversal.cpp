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
    TreeNode* helperBuildTree(vector<int>& preorder, vector<int>& inorder,
                              int node, int l, int r,
                              unordered_map<int, int>& mpp) {
        if (l > r)
            return nullptr;
        TreeNode* head = new TreeNode(preorder[node]);
        if (l == r)
            return head;
        int idx = mpp[preorder[node]];
        head->left =
            helperBuildTree(preorder, inorder, node + 1, l, idx - 1, mpp);
        head->right = helperBuildTree(preorder, inorder, node + idx - l + 1,
                                      idx + 1, r, mpp);
        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n < 1)
            return nullptr;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[inorder[i]] = i;
        return helperBuildTree(preorder, inorder, 0, 0, n - 1, mpp);
    }
};