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
class Pair
{
public:
    int maxSum;
    int branchSum;
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
Pair maxSumPath(node*root)
{
    Pair p;
    if(root == nullptr)
    {
        p.maxSum = p.branchSum = 0;
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);
    int op1 = root->data;
    int op2 = root->data + left.branchSum;
    int op3 = root->data + right.branchSum;
    int op4 = root->data + left.branchSum + right.branchSum;
    int ans_through_curr_node = max(op1, max(op2, max(op3,op4)));

    p.branchSum = max(left.branchSum,right.branchSum) + root->data;
    p.maxSum = max(ans_through_curr_node, max(left.maxSum, right.maxSum));
    return p;
}
int main()
{
    node*root = buildTree();
    cout<<maxSumPath(root).maxSum;
}
/*
10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
*/
// LEETCODE
class Solution
{
public:
   int maxPathSum(TreeNode *root) {
    int maxPath = INT_MIN;
    dfsMaxPath(root, maxPath);
    return maxPath;
}

int dfsMaxPath(TreeNode *root, int &maxPath)
{
    if (!root) return 0;
    int l = max(0, dfsMaxPath(root->left, maxPath));
    int r = max(0, dfsMaxPath(root->right, maxPath));
    maxPath = max(maxPath, l + r + root->val);
    return root->val + max(l, r);
}
};
