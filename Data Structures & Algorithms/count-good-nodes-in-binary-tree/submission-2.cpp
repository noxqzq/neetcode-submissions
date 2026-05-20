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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
private:
    int dfs(TreeNode* node, int maxSoFar) {
        if(!node){
            return 0;
        }
        int count{};

        if (node->val >= maxSoFar) {
            count += 1;
        }

        int newMax = max(node->val, maxSoFar);

        count += dfs(node->left, newMax);
        count += dfs(node->right, newMax);

        return count;
    }
};
