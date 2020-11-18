//LEETCODE


class Solution {
public:
    int H;
    int sum = 0;
    int height(TreeNode*root)
    {
        if(root == nullptr)
            return 0;
        int ls = height(root->left);
        int rs = height(root->right);
        return 1 + max(ls, rs);
    }
    int deepestLeavesSum(TreeNode* root)
    {
        H = height(root);
        solve(root, 1, H);
        return sum;
    }
    void solve(TreeNode*root, int level, int H)
    {
        if(root == nullptr)
            return;
        if(level == H)
        {
            sum += root->val;
            return;
        }
        solve(root->left, level + 1, H);
        solve(root->right, level + 1,H);
    }
};
