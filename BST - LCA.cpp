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
node*lca(node*root,int a,int b)
{
    if(root == nullptr)
        return nullptr;
    if(a < root->data && b < root->data)
        return lca(root->left,a,b);
    if(a > root->data && b > root->data)
        return lca(root->right,a,b);
    return root;
}
int main()
{
    node*root = buildBST();
    cout<<lca(root,3,8)->data;
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 -1
5 3 1 2 4 8 6 9 -1
5 3 7 1 6 8 -1
*/
