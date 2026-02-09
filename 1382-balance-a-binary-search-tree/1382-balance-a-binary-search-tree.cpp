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
    void convertTreeToArr(TreeNode *root, vector<TreeNode*>& arr){
        if(!root) return;
        convertTreeToArr(root->left, arr);
        arr.emplace_back(root);
        convertTreeToArr(root->right, arr);
    }
    TreeNode* convertToBST(vector<TreeNode*>&arr, int low, int high){
        if(low > high) return nullptr;
        int mid = (low + high) / 2;
        TreeNode *node = arr[mid];
        node->left = convertToBST(arr, low, mid - 1);
        node->right = convertToBST(arr, mid + 1, high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> arr;
        convertTreeToArr(root, arr);
        TreeNode *bst = convertToBST(arr, 0, arr.size() - 1);
        return bst;
    }
};