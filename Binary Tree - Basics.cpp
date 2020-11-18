#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};
node*buildTree()
{
    int d;
    cin>>d;
    if(d == -1)
        return nullptr;
    node*root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void preOrder(node*root)
{
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node*root)
{
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node*root)
{
    if(root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int height(node*root)
{
    if(root == nullptr)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return 1 + max(ls, rs);
}
void printKthLevel(node*root, int k)
{
    if(root == nullptr)
        return;
    if(k == 1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}
void printAllLevels(node*root)
{
    if(root == nullptr)
        return;
    int H = height(root);
    for(int k = 1;k <= H;k++)
    {
        printKthLevel(root, k);
    }
}
void bfs(node*root)
{
    if(root == nullptr)
        return;
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node*f = q.front();
        q.pop();
        if(f == nullptr)
        {
            cout<<endl;
            if(!q.empty())
                q.push(nullptr);
            else
                break;
        }
        else
        {
            cout<<f->data<<" ";
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
}
int main()
{
    node*root = buildTree();
    preOrder(root);
    cout<<endl;
    postOrder(root);
    //bfs(root);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
*/
