// https://neetcode.io/problems/valid-binary-search-tree?list=blind75

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode* root, int min, int max)
    {
        if(!root)
            return true;
        
        return (root->val > min && root->val < max) &&
         isValidBST(root->left, min, root->val) &&
         isValidBST(root->right,root->val, max);
    }
};
