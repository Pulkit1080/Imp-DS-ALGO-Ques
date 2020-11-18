//GFG

//Way 1 --> O(n*n) Time  O(1) Space
bool isIdentical(Node* mainTree, Node* subTree)
{
    if(mainTree == nullptr && subTree == nullptr)
        return 1;
    if(mainTree == nullptr || subTree == nullptr)
        return 0;
    return mainTree->data == subTree->data && isIdentical(mainTree->left, subTree->left) && isIdentical(mainTree->right, subTree->right);
}
bool isSubTree(Node* mainTree, Node* subTree)
{
    if(subTree == nullptr)
        return 1;
    if(mainTree == nullptr)
        return 0;
    if(isIdentical(mainTree, subTree))
        return 1;
    return isSubTree(mainTree->left, subTree) || isSubTree(mainTree->right, subTree);
}


//Way 2 --> O(n) Time  O(n) Space --> strstr() does not work on gfg KMP (which stores array of num) does
void storePreorder(Node* root, char a[], int &i)
{
    if(root == nullptr)
    {
        a[i++] = '$';
        //to store end to handle special case like: -
        /*
                                Tree1   ->  subtree
                                  x
                                /   \
                              a      b
                             /
                            c


                                Tree2   ->  mainTree
                                  x
                                /    \
                              a       b
                             /         \
                            c           d
        */
        return;
    }
    a[i++] = root->data;
    storePreorder(root->left, a, i);
    storePreorder(root->right, a, i);
}
void storeInorder(Node* root, char a[], int &i)
{
    if(root == nullptr)
    {
        a[i++] = '$';
        return;
    }
    storeInorder(root->left, a, i);
    a[i++] = root->data;
    storeInorder(root->right, a, i);
}
bool isSubTree(Node* mainTree, Node* subTree)
{
    if(subTree == nullptr)
        return 1;
    if(mainTree == nullptr)
        return 0;
    //Compare Inorder
    char inorderMainTree[100005], inorderSubTree[100005];
    int m = 0;
    int n = 0;
    storeInorder(mainTree, inorderMainTree, m);
    storeInorder(subTree, inorderSubTree, n);
    inorderMainTree[m] = '\0';
    inorderSubTree[n] = '\0';
    //Compare Preorder
    char preorderMainTree[100005], preorderSubTree[100005];
    m = 0;
    n = 0;
    storePreorder(mainTree, preorderMainTree, m);
    storePreorder(subTree, preorderSubTree, n);
    preorderMainTree[m] = '\0';
    preorderSubTree[n] = '\0';
    return (strstr(inorderMainTree, inorderSubTree) && strstr(preorderMainTree, preorderSubTree));
}
