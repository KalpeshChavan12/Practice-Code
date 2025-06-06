// https://neetcode.io/problems/binary-tree-diameter?list=blind75

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        dt(root, res);
        return res-1;
    }

    int dt(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        
        int ldepth = dt(root->left, res);
        int rdepth = dt(root->right, res); 
        int depth = 1 + max(ldepth, rdepth);

        res = max(1 + ldepth+rdepth, res);

        return depth;
    }
};
