//LEETCODE

class Solution {
public:
    int len = 0;
    int longestUnivaluePath(TreeNode* root)
    {
        if(root == nullptr)
            return len;
        solve(root, root->val);
        return len;
    }
    int solve(TreeNode* root,int val)
    {
        if(root == nullptr)
            return 0;
        int left = solve(root->left, root->val);
        int right = solve(root->right, root->val);
        len = max(len, left + right);
        if(val == root->val)
            return max(left, right) + 1;
        else
            return 0;
    }
};
