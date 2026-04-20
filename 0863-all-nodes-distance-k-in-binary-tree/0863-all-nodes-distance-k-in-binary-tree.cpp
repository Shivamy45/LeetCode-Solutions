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
    void helperDistanceK(unordered_map<TreeNode*, TreeNode*>& mpp,
                         TreeNode* root) {
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
    }

    vector<int>
    helperDistanceK2(TreeNode* target, int k,
                     unordered_map<TreeNode*, TreeNode*>& parentMap) {
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        TreeNode* curr = target;
        vis.insert(curr);
        q.push(curr);
        int lvl = 0;
        while (!q.empty()) {
            int size = q.size();
            if (lvl++ == k)
                break;
            for (int i = 0; i < size; i++) {
                curr = q.front();
                q.pop();
                if (curr->left && vis.find(curr->left) == vis.end()) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && vis.find(curr->right) == vis.end()) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
                if (parentMap.count(curr) &&
                    vis.find(parentMap[curr]) == vis.end()) {
                    vis.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        // update parent map
        helperDistanceK(parentMap, root);

        return helperDistanceK2(target, k, parentMap);
    }
};