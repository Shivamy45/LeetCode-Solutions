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
    void levelSum(TreeNode* root, int lvl,
                  unordered_map<int, long long>& sumOfLvl) {
        sumOfLvl[lvl] += root->val;
        if (root->left)
            levelSum(root->left, lvl + 1, sumOfLvl);
        if (root->right)
            levelSum(root->right, lvl + 1, sumOfLvl);
    }
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, long long> sumOfLvl;
        levelSum(root, 1, sumOfLvl);
        int maxLvl = 1;
        for (auto& it : sumOfLvl) {
            if (sumOfLvl[maxLvl] <= it.second) {
                maxLvl = it.first;
            }
        }
        return maxLvl;
    }
};