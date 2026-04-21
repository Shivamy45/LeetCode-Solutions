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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while (!q.empty()) {
            bool stop = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left){
                    ans++;
                    q.push(node->left);
                }
                if (node->right){
                    ans++;
                    q.push(node->right);
                }
                if (!node->left || !node->right){
                    stop = true;
                    break;
                }
            }
            if(stop) break;
        }
        return ans;
    }
};