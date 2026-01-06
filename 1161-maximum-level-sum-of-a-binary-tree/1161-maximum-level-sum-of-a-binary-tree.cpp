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
    void levelSum(TreeNode* root, int lvl, vector<long long>& sumOfLvl) {
        if (!root)
            return;
        if(sumOfLvl.size() <= lvl) sumOfLvl.push_back(root->val);
        else sumOfLvl[lvl] += root->val;
        if (root->left)
            levelSum(root->left, lvl + 1, sumOfLvl);
        if (root->right)
            levelSum(root->right, lvl + 1, sumOfLvl);
    }
    int maxLevelSum(TreeNode* root) {
        vector<long long> sumOfLvl;
        levelSum(root, 0, sumOfLvl);
        return max_element(sumOfLvl.begin(), sumOfLvl.end()) -
               sumOfLvl.begin() + 1;
    }
};