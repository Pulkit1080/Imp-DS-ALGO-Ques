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
node*insertInBST(node* root, int d)
{
    if(root == nullptr)
        return new node(d);
    if(d < root->data)
        root->left = insertInBST(root->left, d);
    else if(d > root->data)
        root->right = insertInBST(root->right, d);
    return root;
}
node*buildBST()
{
    node*root = nullptr;
    int d;
    cin>>d;
    while(d != -1)
    {
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}
void bfs(node* root)
{
    if(!root)
        return;
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == nullptr)
        {
            cout<<endl;
            if(q.empty())
                break;
            else
                q.push(nullptr);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}
node* find_lca(node* root, int a, int b)
{
    if(!root)
        return nullptr;
    if(a < root->data && b < root->data)
        return find_lca(root->left, a, b);
    if(a > root->data && b > root->data)
        return find_lca(root->right, a, b);
    return root;
}
int ans = INT_MIN;
void maxTillNode(node* root, int x)
{
    if(root == nullptr)
        return;
    ans = max(ans, root->data);
    if(root->data == x)
        return;
    if(x > root->data)
        maxTillNode(root->right, x);
    if(x < root->data)
        maxTillNode(root->left, x);
}
int findMaxBetweenTwo(node* root, int a, int b)
{
    node*lca = find_lca(root, a, b);
    maxTillNode(lca, a);
    int max1 = ans;
    ans = INT_MIN;
    maxTillNode(lca, b);
    int max2 = ans;
    return max(max1, max2);
}
int main()
{
    node*root = buildBST();
    //bfs(root);
    int a, b;
    cin>>a>>b;
    cout<<findMaxBetweenTwo(root, a, b);
}
/*
18 36 9 6 12 10 1 8 -1
1 10
*/
