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
class Pair
{
public:
    int height;
    int diameter;
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
int height(node*root)
{
    if(root == nullptr)
        return 0;
    int ls = height(root->left);
    int rs = height(root->right);
    return 1 + max(ls, rs);
}
int CountNodes(node*root)
{
    if(root == nullptr)
        return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}
int SumNodes(node*root)
{
    if(root == nullptr)
        return 0;
    return root->data + SumNodes(root->left) + SumNodes(root->right);
}
int diameter(node*root)
{
    if(root == nullptr)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1,max(op2,op3));
}
Pair fastDiameter(node*root)
{
    Pair p;
    if(root == nullptr)
    {
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    p.height = 1 + max(left.height, right.height);
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}
int SumReplacement(node*root)
{
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return root->data;
    int left = SumReplacement(root->left);
    int right = SumReplacement(root->right);
    int temp = root->data;
    root->data = left + right;
    return temp + root->data;
}
int main()
{
    node*root = buildTree();
    SumReplacement(root);
    bfs(root);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
*/
