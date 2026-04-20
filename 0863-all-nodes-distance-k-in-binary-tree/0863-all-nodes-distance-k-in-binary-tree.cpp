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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        vector<int> res;
        unordered_set<int> vis;
        TreeNode* curr = target;
        queue<pair<TreeNode*, int>> qt;
        qt.push({curr, 0});
        while (!qt.empty()) {
            auto [node, step] = qt.front();
            qt.pop();
            if (vis.find(node->val) != vis.end())
                continue;
            vis.insert(node->val);
            if (step == k)
                res.push_back(node->val);
            if (node->left)
                qt.push({node->left, step + 1});
            if (node->right)
                qt.push({node->right, step + 1});
            if (mpp.count(node))
                qt.push({mpp[node], step + 1});
        }
        return res;
    }
};