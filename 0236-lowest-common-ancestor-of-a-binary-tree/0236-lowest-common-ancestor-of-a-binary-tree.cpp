/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helperHelperLowestCommonAncestor(TreeNode* root, TreeNode* x,
                                          vector<TreeNode*>& res) {
        if (!root)
            return false;
        res.push_back(root);
        if (root->val == x->val)
            return true;
        if (helperHelperLowestCommonAncestor(root->left, x, res) ||
            helperHelperLowestCommonAncestor(root->right, x, res))
            return true;
        res.pop_back();
        return false;
    }

    vector<TreeNode*> helperLowestCommonAncestor(TreeNode* root,
                                                 TreeNode* val) {
        vector<TreeNode*> res;
        helperHelperLowestCommonAncestor(root, val, res);
        return res;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath = helperLowestCommonAncestor(root, p);
        unordered_map<TreeNode*, int> mpp;
        for (auto it : pPath) {
            mpp[it] = 1;
        }
        vector<TreeNode*> qPath = helperLowestCommonAncestor(root, q);
        TreeNode* res = nullptr;
        for (auto it : qPath) {
            if (mpp.find(it) != mpp.end())
                res = it;
        }
        return res;
    }
};