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
class LinkedList
{
public:
    node*head;
    node*tail;
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
LinkedList flattenBST(node*root)
{
    LinkedList l;
    if(root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        l.head = l.tail = root;
        return l;
    }
    if(root->left != nullptr && root->right == nullptr)
    {
        LinkedList left = flattenBST(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }
    if(root->left == nullptr && root->right != nullptr)
    {
        LinkedList right = flattenBST(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    if(root->left != nullptr && root->right != nullptr)
    {
        LinkedList left = flattenBST(root->left);
        LinkedList right = flattenBST(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
}
int main()
{
    node*root = buildBST();
    LinkedList l = flattenBST(root);
    node*temp = l.head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 -1
5 3 1 2 4 8 6 9 -1
5 3 7 1 6 8 -1
*/
