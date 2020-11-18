//LEETCODE
class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
         return solve(nums, 0, nums.size() - 1);
    }
    TreeNode*solve(vector<int>&nums, int s, int e)
    {
        if(s > e)
            return nullptr;
        int maxNo = -1;
        int maxIdx = -1;
        for(int i = s;i <= e;i++)
        {
            if(nums[i] > maxNo)
            {
                maxNo = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = solve(nums, s, maxIdx - 1);
        root->right = solve(nums, maxIdx + 1, e);
        return root;
    }
};
