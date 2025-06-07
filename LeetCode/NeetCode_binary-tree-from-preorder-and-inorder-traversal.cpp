// https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal?list=blind75

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        {
            return NULL;
        }
        map<int, int> index;
        for(int i=0; i<inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        int i=0;
        return buildTree(preorder, i, index, 0,  inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int& i, map<int, int>& index, int l, int r) {
        int s =preorder.size();

        if(l>r)
            return NULL;

       int val = preorder[i++];
       TreeNode* root = new TreeNode(val);
       root->left = buildTree(preorder, i, index, l, index[val]-1);
       root->right = buildTree(preorder, i, index, index[val]+1, r);

        return root;

    }
};
