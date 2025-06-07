// https://neetcode.io/problems/binary-tree-maximum-path-sum?list=blind75


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
int maxPathSum(TreeNode* root) {
        int maxDepth = INT_MIN;
        int res = INT_MIN;

        maxPathSum(root, maxDepth, res);

        return res;
    }

    void maxPathSum(TreeNode* root, int& maxDepth, int& res)
    {
        int _maxDepth = INT_MIN;
        if(!root)
            return;

        int ld=0, rd=0;

        maxPathSum(root->left, ld, res);
        maxPathSum(root->right, rd, res);

        if(ld == INT_MIN && rd == INT_MIN)
        {
            _maxDepth = root->val;
            res = max(res, root->val);
        }
        else if(ld == INT_MIN)
        {
            _maxDepth = max(root->val + rd, root->val);
            res = max(res, _maxDepth); 
        }
        else if(rd == INT_MIN)
        {
            _maxDepth = max(root->val + ld, root->val);
            res = max(res, _maxDepth); 
        }
        else
        {
            _maxDepth = max(root->val + ld, root->val + rd);
            _maxDepth = max(root->val, _maxDepth);
            res = max(res, root->val + ld + rd);
            res = max(res, root->val + ld);
            res = max(res, root->val + rd);
            res = max(res, root->val);
        }

        maxDepth = _maxDepth;
    }
};
