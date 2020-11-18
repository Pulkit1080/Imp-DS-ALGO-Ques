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
void findMinMax(node*root, int &min, int &max, int hd)
{
    if (root == NULL)
        return;
    if (hd < min)
        min = hd;
    else if (hd > max)
        max = hd;
    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);
}
void printVerticalLine(node*root, int line_no, int hd)
{
    if (root == NULL)
        return;
    if (hd == line_no)
        cout << root->data << " ";
    printVerticalLine(root->left, line_no, hd-1);
    printVerticalLine(root->right, line_no, hd+1);
}
void printVerticalView_1(node*root)       // O(n*n) Time, O(1) Space
{
    int min = 0, max = 0;
    findMinMax(root, min, max, 0);
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout<<endl;
    }
}


void printVerticalView_2(node*root)       //  O(n) Time, O(n) Space
{
    unordered_map<int,vector<int>>mp;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int>Node_pair = q.front();
        q.pop();
        node*Node = Node_pair.first;
        int hd = Node_pair.second;
        mp[hd].push_back(Node->data);
        if(Node->left)
            q.push(make_pair(Node->left,hd-1));
        if(Node->right)
            q.push(make_pair(Node->right,hd+1));
    }

    for(auto p:mp)
    {
        for(auto it:p.second)
            cout<<it<<" ";
        cout<<endl;
    }
}


void printBottomView(node*root)
{
    map<int,vector<int>>mp;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int>Node_pair = q.front();
        q.pop();
        node*Node = Node_pair.first;
        int hd = Node_pair.second;
        mp[hd].push_back(Node->data);
        if(Node->left)
            q.push(make_pair(Node->left,hd-1));
        if(Node->right)
            q.push(make_pair(Node->right,hd+1));
    }

    for(auto it:mp)
    {
        cout<<it.second[it.second.size() - 1]<<" ";
    }
}
int main()
{
    node*root = buildTree();
    //bfs(root);
    printVerticalView_1(root);
    //printVerticalView_2(root);
    //printBottomView(root);
}
/*
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 8 -1 -1 9 -1 -1
1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
*/
