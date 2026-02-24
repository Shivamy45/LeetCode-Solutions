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
    int path(TreeNode* root, string& temp) {
        if (!root->left && !root->right) {
            temp.push_back('0' + root->val);
            int num = stoi(temp, nullptr, 2);
            temp.pop_back();
            return num;
        }
        int sum = 0;
        temp.push_back('0' + root->val);
        if (root->left) {
            sum += path(root->left, temp);
        }
        if (root->right) {
            sum += path(root->right, temp);
        }
        temp.pop_back();
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp = "";
        return path(root, temp);
    }
};