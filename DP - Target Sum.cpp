//LEETCODE

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int sum = 0;
        int cnt = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if(nums[i] == 0)
                cnt++;
        }
        if(S > sum || (S + sum) % 2 != 0)
            return 0;
        int s = (S + sum)/2;
        int n = nums.size();
        int dp[n+1][s+1];
        for(int i = 0;i < n+1;i++)
        {
            for(int j = 0;j < s+1;j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }
        for(int i = 1;i < n+1;i++)
        {
            for(int j = 1;j < s+1;j++)
            {
                if(nums[i-1] == 0)
                    dp[i][j] = dp[i-1][j];
                else if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return pow(2,cnt) * dp[n][s];
    }
};
