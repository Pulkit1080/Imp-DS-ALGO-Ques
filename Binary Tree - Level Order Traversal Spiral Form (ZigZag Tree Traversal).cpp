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
void spiralLevelOrder_1(node*root)      //  1st normal, 2nd rev, 3rd normal, 4th rev etc...
{
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node*temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty())
        {
            node*temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }
}
void spiralLevelOrder_2(node*root)      //  1st rev, 2nd normal, 3rd rev, 4th normal etc...
{
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node*temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        while(!s2.empty())
        {
            node*temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }
}
int main()
{
    node*root = buildTree();
    bfs(root);
    cout<<endl;
    spiralLevelOrder_1(root);
    cout<<endl;
    spiralLevelOrder_2(root);
}
/*
3 4 -1 6 -1 -1 5 1 -1 -1 -1
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
5 1 2 -1 -1 -1 1 -1 2 -1 -1
8 10 1 20 -1 -1 81 -1 -1 6 9 -1 -1 7 -1 -1 3 4 0 -1 -1 41 -1 -1 14 2 -1 -1 11 -1 -1
*/
