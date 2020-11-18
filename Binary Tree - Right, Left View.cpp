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
void printRightView(node*root, int level, int &maxLevel)
{
    if(root == nullptr)
        return;
    if(level > maxLevel)
    {
        cout<<root->data<<" ";
        maxLevel = level;
    }
    printRightView(root->right, level + 1,maxLevel);
    printRightView(root->left, level + 1,maxLevel);
}
void printLeftView(node*root, int level, int &maxLevel)
{
    if(root == nullptr)
        return;
    if(level > maxLevel)
    {
        cout<<root->data<<" ";
        maxLevel = level;
    }
    printLeftView(root->left, level + 1,maxLevel);
    printLeftView(root->right, level + 1,maxLevel);
}
int main()
{
    node*root = buildTree();
    int maxLevel = -1;
    //printRightView(root, 0, maxLevel);
    printLeftView(root, 0, maxLevel);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
*/
