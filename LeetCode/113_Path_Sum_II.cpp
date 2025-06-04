// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        pathSum(root, path, targetSum, 0, res);
        return res;
    }

    void pathSum(TreeNode *root, vector<int>& top, int targetSum, int psum, vector<vector<int>>& res)
    {
        if(!root)
        {
            return;
        }

        if(!root->left && !root->right)
        {
            int s = psum + root->val;
            
            if(s == targetSum)
            {
                vector<int> v(top.begin(), top.end());
                v.push_back(root->val);
                res.push_back(v);
            }
        }

        top.push_back(root->val);
        pathSum(root->left, top, targetSum, psum + root->val, res);
        pathSum(root->right, top, targetSum, psum + root->val, res);
        top.pop_back();
    }
};
