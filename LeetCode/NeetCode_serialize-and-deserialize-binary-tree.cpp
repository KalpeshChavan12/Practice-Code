// https://neetcode.io/problems/serialize-and-deserialize-binary-tree?list=blind75

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    void serialize(TreeNode* root, stringstream& ss)
    {
        if(!root)
        {
            ss<<"N;";
            return;
        }

        ss<<root->val<<";";
        serialize(root->left, ss);
        serialize(root->right, ss);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root=NULL;

        stringstream ss(data);
        
        vector<int> nodes; 
        string token;
        while(std::getline(ss, token, ';') && token != "")
        {
           if(token == "N")
                nodes.push_back(INT_MIN);
            else
                nodes.push_back(atoi(token.c_str()));
        }
        int i=0;
        return deserialize(nodes, i);
    }

    TreeNode* deserialize(vector<int>& nodes, int& i)
    {
        if(i> nodes.size())
            return NULL;
        
        if(nodes[i] == INT_MIN)
        {
            i++;
            return NULL;
        }

        TreeNode* curr = new TreeNode(nodes[i]);
        i++;
        curr->left = deserialize(nodes, i);
        curr->right = deserialize(nodes, i);

        return curr;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
