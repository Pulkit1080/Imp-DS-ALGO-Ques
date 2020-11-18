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
int max_num_in_nodes_1(node* root, int sum)
{
    if(root == nullptr)
        return 0;
    if(root->left == nullptr && root->right == nullptr)
        return sum * 10 + root->data;
    return max(max_num_in_nodes_1(root->left, sum*10 + root->data), max_num_in_nodes_1(root->right, sum*10 + root->data));
}
class Pair
{
public:
    int data;
    int height;
};
Pair max_num_in_nodes_2(node* root)
{
    Pair p;
    if(root == nullptr)
    {
        p.data = p.height = 0;
        return p;
    }
    else if(root->left == nullptr && root->right == nullptr)
    {
        p.data = root->data;
        p.height = 1;
        return p;
    }
    Pair left = max_num_in_nodes_2(root->left);
    Pair right = max_num_in_nodes_2(root->right);
    p.height = max(left.height, right.height) + 1;
    p.data = (root->data * pow(10, p.height - 1) ) + max(left.data, right.data);
    return p;
}
int main()
{
    node*root = buildTree();
    //bfs(root);
    cout<<max_num_in_nodes_1(root, 0);
    cout<<endl;
    cout<<max_num_in_nodes_2(root).data;
}
/*
1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/

