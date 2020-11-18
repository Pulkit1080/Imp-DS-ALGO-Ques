//GFG

void printLeaves(Node* root, vector <int> &res)
{
    if (root == NULL)
        return;
    printLeaves(root->left, res);
    if (!(root->left) && !(root->right))
        res.push_back (root->data);
    printLeaves(root->right, res);
}
void printBoundaryLeft(Node* root, vector <int> &res)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        res.push_back(root->data);
        printBoundaryLeft(root->left, res);
    }
    else if (root->right)
    {
        res.push_back(root->data);
        printBoundaryLeft(root->right, res);
    }
    // do nothing if it is a leaf node, this way we avoid duplicates in output
}
void printBoundaryRight(Node* root, vector <int> &res)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        // to ensure bottom up order, first call for right subtree, then print this node
        printBoundaryRight(root->right, res);
        res.push_back(root->data);
    }
    else if (root->left)
    {
        printBoundaryRight(root->left, res);
        res.push_back (root->data);
    }
    // do nothing if it is a leaf node, this way we avoid duplicates in output
}
vector <int> printBoundary(Node* root)
{
    vector <int> res;
    if (root == NULL)
        return res;

    res.push_back (root->data);
    printBoundaryLeft(root->left, res);

    printLeaves(root->left, res);
    printLeaves(root->right, res);

    printBoundaryRight(root->right, res);
    return res;
}

