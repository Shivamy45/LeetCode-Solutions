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
    int dfs(TreeNode *root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return 1 + max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int leftSubTree = dfs(root->left);
        int rightSubTree = dfs(root->right);
        if(leftSubTree == rightSubTree) return root;
        else if(leftSubTree > rightSubTree) return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }
};