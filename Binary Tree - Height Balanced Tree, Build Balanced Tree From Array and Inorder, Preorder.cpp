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
    bool balanced;
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
Pair isBalanced(node*root)
{
    Pair p;
    if(root == nullptr)
    {
        p.balanced = true;
        p.height = 0;
        return p;
    }
    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);
    p.height = 1 + max(left.height, right.height);
    if(left.balanced && right.balanced && abs(left.height - right.height) <= 1)
        p.balanced = true;
    else
        p.balanced = false;
    return p;
}
node*BuildFromArray(int a[],int s,int e)
{
    if(s > e)
        return nullptr;
    int mid = s + (e - s)/2;
    node*root = new node(a[mid]);
    root->left = BuildFromArray(a, s, mid-1);
    root->right = BuildFromArray(a, mid+1, e);
    return root;
}
node*BuildFromPreIn(int pre[], int in[], int s, int e)
{
    if(s > e)
        return nullptr;
    static int i = 0;
    node*root = new node(pre[i]);
    int index = -1;
    for(int j = s;j <= e;j++)
        if(pre[i] == in[j])
            index = j;
    i++;
    root->left = BuildFromPreIn(pre, in, s, index-1);
    root->right = BuildFromPreIn(pre, in, index+1, e);
    return root;
}
int main()
{
    //node*root = buildTree();
    //cout<<isBalanced(root).balanced;

    /*int a[] = {1,2,3,4,5,6};
    int n = 6;
    node*root = BuildFromArray(a,0,n-1);
    bfs(root);*/

    int pre[] = {1,2,3,4,8,5,6,7};
    int in[] = {3,2,8,4,1,6,7,5};
    int n = 8;
    node*root = BuildFromPreIn(pre,in,0,n-1);
    bfs(root);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
*/
