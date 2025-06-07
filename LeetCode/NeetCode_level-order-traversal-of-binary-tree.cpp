// https://neetcode.io/problems/level-order-traversal-of-binary-tree?list=blind75


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        if(!root)
            return res;

        q.push(root);

        while(!q.empty())
        {
            queue<TreeNode*> tq;
            vector<int> l;
            while(!q.empty())
            {
                auto n = q.front();
                l.push_back(n->val);
                if(n->left)
                    tq.push(n->left);
                if(n->right)
                    tq.push(n->right);
                q.pop();
            }

            res.push_back(l);
            q = tq;
        }

        return res;
    }
};
