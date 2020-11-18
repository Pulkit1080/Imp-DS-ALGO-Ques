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
void BSTtoDLL(node*root,node*&head)
{
    if(root == nullptr)
        return;
    static node*prev = nullptr;
    BSTtoDLL(root->left,head);
    if(prev == nullptr)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BSTtoDLL(root->right,head);
}
int main()
{
    /*node*root = buildBST();
    node*head = nullptr;
    BSTtoDLL(root, head);
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->right;
    }*/
    node*root = buildTree();
    //bfs(root);
    node*head = nullptr;
    BSTtoDLL(root, head);
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 -1
5 3 1 2 4 8 6 9 -1
5 3 7 1 6 8 -1

1 3 5 5 -1 -1 5 -1 -1 7 9 -1 -1 2 -1 -1 10 9 10 -1 -1 -1 -1
*/
