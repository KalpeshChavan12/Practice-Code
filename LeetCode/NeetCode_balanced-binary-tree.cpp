// https://neetcode.io/problems/balanced-binary-tree?list=blind75


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
        if(!root)
            return true;
        int d;

        return isBalanced(root, d);        

    }

    bool isBalanced(TreeNode* root, int& depth)
    {
        if(!root)
        {
            depth=0;
            return true;
        }
        int ld, rd;
        if(isBalanced(root->left, ld) && isBalanced(root->right, rd))
        {
            depth = 1 + max(rd, ld);
            if(abs(ld-rd) <= 1)
            {
                    return true;
            }
            return false;
        }

        return false;
    }
};
