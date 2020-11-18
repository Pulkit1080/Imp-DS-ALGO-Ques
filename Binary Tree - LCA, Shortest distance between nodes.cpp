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
void bfs(node*root)
{
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
node*lca(node*root, int a, int b)
{
    if(root == nullptr)
        return nullptr;
    if(root->data == a || root->data == b)
        return root;
    node*left = lca(root->left, a, b);
    node*right = lca(root->right, a, b);
    if(left != nullptr && right != nullptr)
        return root;
    if(left != nullptr)
        return left;
    return right;
}
int search(node*root,int i,int level)
{
    if(root == nullptr)
        return -1;
    if(root->data == i)
    {
        return level;
    }
    int left = search(root->left,i,level + 1);
    if(left != -1)
        return left;
    else
        return search(root->right,i,level + 1);
}
int findDistance(node*root, int a,int b)
{
    if(root == nullptr)
        return 0;
    node*L_C_A = lca(root,a,b);
    int l1 = search(L_C_A,a,0);
    int l2 = search(L_C_A,b,0);
    return l1 + l2;
}
int main()
{
    node*root = buildTree();
    cout<<findDistance(root,6,9);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
*/
