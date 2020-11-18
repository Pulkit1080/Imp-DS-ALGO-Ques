#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node*left;
    node*right;
    node*nextRight;
    node(int d)
    {
        data = d;
        left = right = nextRight = nullptr;
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
            if(f->nextRight == nullptr)
                cout<<"N ";
            else
                cout<<f->nextRight->data<<" ";
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
}
void ConnectNodeAtSameLevel_1(node*root)    //  level order traversal On time, On space
{
    if(root == nullptr)
        return;
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node*temp = q.front();
        q.pop();
        if(temp == nullptr)
        {
            if(!q.empty())
                q.push(nullptr);
            else
                break;
        }
        else
        {
            temp->nextRight = q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
node*getnextRight(node*root)
{
    node*temp = root->nextRight;
    if(temp != nullptr)
    {
        if(temp->left != nullptr)
            return temp->left;
        if(temp->right != nullptr)
            return temp->right;
    }
    return nullptr;
}
void ConnectNodeAtSameLevel_2(node*root)    //  preorder traversal On time, O1 space
{
    if(root == nullptr)
        return;
    if(root->left)
    {
        if(root->right)
            root->left->nextRight = root->right;
        else
            root->left->nextRight = getnextRight(root);
    }
    if(root->right)
        root->right->nextRight = getnextRight(root);
    ConnectNodeAtSameLevel_2(root->left);
    ConnectNodeAtSameLevel_2(root->right);
}
int main()
{
    node*root = buildTree();
    //ConnectNodeAtSameLevel_1(root);
    ConnectNodeAtSameLevel_2(root);
    bfs(root);  //modified to print nextRight for every node
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
*/
