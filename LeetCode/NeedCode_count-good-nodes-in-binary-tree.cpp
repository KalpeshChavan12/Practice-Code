// https://neetcode.io/problems/count-good-nodes-in-binary-tree?list=blind75

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
        int res=0;
        goodNodes(root, INT_MIN, res);
        return res;
    }

    void goodNodes(TreeNode* root, int pmax, int& res)
    {
        if(!root)
            return;
        
        if(root->val >= pmax)
            res++;
        
        pmax=max(pmax, root->val);

        goodNodes(root->left, pmax, res);
        goodNodes(root->right, pmax, res);
    }
};
