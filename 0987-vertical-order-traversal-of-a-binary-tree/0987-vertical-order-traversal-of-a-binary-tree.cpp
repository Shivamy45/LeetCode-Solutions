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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
    queue<tuple<TreeNode *, int, int>> q;
    // {node, {col, lvl}}
    q.push({root, 0, 0});
    while (!q.empty())
    {
        auto [node, col, lvl] = q.front();
        q.pop();
        mpp[col][lvl].insert(node->val);
        if (node->left)
            q.push({node->left, col - 1, lvl + 1});
        if (node->right)
            q.push({node->right, col + 1, lvl + 1});
    }
    vector<vector<int>> res;
    for (auto &col : mpp)
    {
        vector<int> temp;
        for (auto &lvl : col.second)
        {
            for (auto val : lvl.second)
            {
                temp.push_back(val);
            }
        }
        res.push_back(temp);
    }
    return res;
    }
};