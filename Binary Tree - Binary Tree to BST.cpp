//GFG

void storeInInorder(Node* root, vector<int>&inorder)
{
    if(root == nullptr)
        return;
    storeInInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInInorder(root->right, inorder);
}
void changeToBST(Node* root, vector<int>&inorder, int &i)
{
    if(root == nullptr)
        return;
    changeToBST(root->left, inorder, i);
    root->data = inorder[i++];
    changeToBST(root->right, inorder, i);
}
Node*binaryTreeToBST(Node* root)
{
    if(root == nullptr)
        return root;
    vector<int>inorder;
    storeInInorder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int i = 0;
    changeToBST(root, inorder, i);
    return root;
}
