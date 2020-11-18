//LEETCODE

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string>ans;
        if(root == nullptr)
            return ans;
        return solve(ans,root,to_string(root->val));
    }
    vector<string>solve(vector<string>&ans,TreeNode*root,string str)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(str);
            return ans;
        }
        if(root->left)
            solve(ans,root->left,str + "->" + to_string(root->left->val));
        if(root->right)
            solve(ans,root->right,str + "->" + to_string(root->right->val));
        return ans;
    }
};
