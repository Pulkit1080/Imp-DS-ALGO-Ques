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
void bfs(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*f = q.front();
        if(f == NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
}
node*InsertInBST(node*root, int d)
{
    if(root == nullptr)
        return new node(d);
    if(d < root->data)
        root->left = InsertInBST(root->left,d);
    else
        root->right = InsertInBST(root->right,d);
    return root;
}
node*buildBST()
{
    node*root = nullptr;
    int d;
    cin>>d;
    while(d != -1)
    {
        root = InsertInBST(root,d);
        cin>>d;
    }
    return root;
}
void flatten_to_preorder(node*root)
{
    if(root == nullptr)
        return;
    flatten_to_preorder(root->left);
    flatten_to_preorder(root->right);
    node*left = root->left;
    node*right = root->right;
    root->left = nullptr;
    root->right = left;
    node*temp = root;
    while(temp->right != nullptr)
        temp = temp->right;
    temp->right = right;
}
void flatten_to_postorder(node*root)
{
    if(root == nullptr)
        return;
    flatten_to_postorder(root->left);
    flatten_to_postorder(root->right);
    node*left = root->left;
    node*right = root->right;
    root->left = right;
    root->right = nullptr;
    node*temp = root;
    while(temp->left != nullptr)
        temp = temp->left;
    temp->left = left;
}
void PrintTree(node*root)
{
    if(root == NULL)
    {
        return;
    }
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}
int main()
{
    node*root = buildBST();
    PrintTree(root);
    cout<<endl;
    flatten_to_preorder(root);
    //flatten_to_postorder(root);
    PrintTree(root);
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 -1
5 3 1 2 4 8 6 9 -1
5 3 7 1 6 8 -1
*/
