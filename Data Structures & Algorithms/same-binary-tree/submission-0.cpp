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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both null → identical at this position
        if (!p && !q) return true;
        
        // One null, one not → mismatch
        if (!p || !q) return false;
        
        // Values differ → mismatch
        if (p->val != q->val) return false;
        
        // Check left subtrees AND right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
