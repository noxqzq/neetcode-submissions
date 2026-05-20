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
    TreeNode* invertTree(TreeNode* root) {
        invertTreee(root);
        return root;
    }
private:
    void invertTreee(TreeNode* root) {
        if (root == nullptr) return;

        // Swap the left and right child pointers
        swap(root->left, root->right);

        // Recurse on both sides
        invertTreee(root->left);
        invertTreee(root->right);
    }
};
