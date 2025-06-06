// https://neetcode.io/problems/subtree-of-a-binary-tree?list=blind75

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
            return true;

        if(!root)
            return false;
        
        return isSame(root, subRoot) ||
        isSubtree(root->left, subRoot) ||
        isSubtree(root->right, subRoot);
                
    }

    bool isSame(TreeNode* a, TreeNode*b)
    {
        if(!a && !b)
            return true;
        
        if((!a && b) || (a && !b))
            return false;
        
        if(a->val == b->val)
        {
            return isSame(a->left, b->left) &&
                isSame(a->right, b->right);
        }

        return false;
    }
};
