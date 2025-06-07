// https://neetcode.io/problems/kth-smallest-integer-in-bst?list=blind75


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
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        int curr=0;
        kthSmallest(root, k, curr, res);
        return res;
    }

    void kthSmallest(TreeNode* root, int k, int& curr, int& res) {
        if(!root)
            return;
        kthSmallest(root->left, k, curr, res);
        curr++;
        if(curr == k)
        {
            res = root->val;
            return;
        }
        kthSmallest(root->right,  k, curr, res);
    }
};
