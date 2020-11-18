//GFG
void reverseAlternate_util(Node*left, Node*right, int level)
{
    if(left == nullptr || right == nullptr)
        return;
    if(level%2 == 0)
        swap(left->data, right->data);
    reverseAlternate_util(left->left, right->right, level + 1);
    reverseAlternate_util(left->right, right->left, level + 1);
}
void reverseAlternate(Node *root)
{
    //Your code here
    if(root == nullptr)
        return;
    int level = 0;
    reverseAlternate_util(root->left, root->right, level);
}
