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
int sum_of_nodes(node* root, int sum)
{
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return sum * 10 + root->data;
    return sum_of_nodes(root->left, sum*10 + root->data) + sum_of_nodes(root->right, sum*10 + root->data);
}
int main()
{
    node*root = buildTree();
    //bfs(root);
    cout<<sum_of_nodes(root, 0);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
= 697
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
= 27490
5 1 2 -1 -1 -1 1 -1 2 -1 -1
= 1024
*/
