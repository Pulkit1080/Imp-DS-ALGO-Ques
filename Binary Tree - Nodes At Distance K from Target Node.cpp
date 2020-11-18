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
void printAtKthLevel(node*root, int k)
{
    if(root == nullptr)
        return;
    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    printAtKthLevel(root->left, k-1);
    printAtKthLevel(root->right, k-1);
}
int printAtKDistance(node*root, int k, node*target)
{
    if(root == nullptr)
        return -1;
    if(root == target)
    {
        printAtKthLevel(root, k);
        return 0;
    }
    int DL = printAtKDistance(root->left,k,target);
    if(DL != -1)
    {
        if(DL + 1 == k)
            cout<<root->data<<" ";
        else
            printAtKthLevel(root->right,k - DL - 2);
        return DL + 1;
    }
    int DR = printAtKDistance(root->right,k,target);
    if(DR != -1)
    {
        if(DR + 1 == k)
            cout<<root->data<<" ";
        else
            printAtKthLevel(root->left,k - DR - 2);
        return DR + 1;
    }
    return -1;
}
int main()
{
    node*root = buildTree();
    printAtKDistance(root,3,root->left->left);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
*/
