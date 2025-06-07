// https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree?list=blind75

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(q->val > root->val  && p->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        if(q->val < root->val  && p->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        if((q->val < root->val  && p->val > root->val) || 
           (q->val > root->val  && p->val < root->val))
        {
            return root;
        }

        if(q->val == root-> val || p->val == root->val)
        {
            return root;
        }

        return root;
    }
};
