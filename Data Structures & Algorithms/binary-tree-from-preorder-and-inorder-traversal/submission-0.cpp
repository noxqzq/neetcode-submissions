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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(preorder, inorder, mp, 0, inorder.size() - 1);
    }
private:
    int preIndex = 0;
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, 
                    unordered_map<int,int>& mp, int start, int end) {
        if(start > end) {
            return nullptr;
        }
        
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        int inorderRootIdx = mp[rootVal];
        
        root->left = helper(preorder, inorder, mp, start, inorderRootIdx - 1);
        root->right = helper(preorder, inorder, mp, inorderRootIdx + 1, end);
        
        return root;
    }
};