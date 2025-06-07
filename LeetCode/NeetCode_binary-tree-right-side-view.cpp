// https://neetcode.io/problems/binary-tree-right-side-view?list=blind75

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if(!root)
            return res;

        q.push(root);

        while(!q.empty())
        {
            queue<TreeNode*> tq;
            while(!q.empty())
            {
                auto& n = q.front();
                if(n->left)
                    tq.push(n->left);
                if(n->right)
                    tq.push(n->right);
                q.pop();
            }

            res.push_back(q.back()->val);
            q=tq;
        }

        return res;
    }
};
