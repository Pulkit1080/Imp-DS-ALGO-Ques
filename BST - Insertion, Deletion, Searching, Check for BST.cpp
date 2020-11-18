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
node*deleteinBST(node*root,int val)
{
    if(root == nullptr)
        return nullptr;
    if(val < root->data)
        root->left = deleteinBST(root->left,val);
    else if(val > root->data)
        root->right = deleteinBST(root->right,val);
    else
    {
        //0 Child
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        //1 Child
        if(root->left != nullptr && root->right == nullptr)
        {
            node*temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == nullptr && root->right != nullptr)
        {
            node*temp = root->right;
            delete root;
            return temp;
        }
        //2 Child
        //Find In-order Successor
        node*Replace = root->right;
        while(Replace->left != nullptr)
            Replace = Replace->left;
        root->data = Replace->data;
        root->right = deleteinBST(root->right,Replace->data);
    }
    return root;
}
bool BSTsearch(node*root, int val)
{
    if(root == nullptr)
        return false;
    if(root->data == val)
        return true;
    if(val < root->data)
        return BSTsearch(root->left,val);
    return BSTsearch(root->right,val);
}
bool isBST(node*root,int minV,int maxV)
{
    if(root == nullptr)
        return true;
    if(root->data <= maxV && root->data >= minV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV))
        return true;
    else
        return false;
}
int main()
{
    node*root = buildBST();
    //cout<<isBST(root, INT_MIN, INT_MAX);
    bfs(root);
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 -1
5 3 1 2 4 8 6 9 -1
5 3 7 1 6 8 -1
18 36 9 6 12 10 1 8 -1
*/
