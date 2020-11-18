//LEETCODE

//Return true if there exits a path with given sum
class Solution
{
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return false;
        if(root->val == sum && root->left == nullptr && root->right == nullptr)
            return true;
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
    }
};


//Path Sum - 2
//Return all paths with given sum
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
    }
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths)
    {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
