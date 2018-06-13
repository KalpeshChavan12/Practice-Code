/*
The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

/*
* Contain function only.
*
*/

bool isBST(Node * root, int min, int max){
    if(!root)
        return true;
    if(root->data  >= min && root->data <= max ){
        return isBST(root->left, min, root->data-1 ) && isBST(root->right , root->data+1, max);
    }
    return false;
}

bool checkBST(Node* root) {
		return isBST(root, INT32_MIN, INT32_MAX);
}
