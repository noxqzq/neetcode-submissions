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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        depthFirst(root->left, leftHeight);
        depthFirst(root->right, rightHeight);
        
        int diff = leftHeight - rightHeight;
        if(diff > 1 || diff < -1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    void depthFirst(TreeNode* node, int& height) {
        if(node == nullptr) return;

        int left = 0, right = 0;
        depthFirst(node->left, left);
        depthFirst(node->right, right);

        height = 1 + max(left, right);
    }
};
