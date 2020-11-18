//INTERVIEW BIT

int Solution::solve(vector<int> &v, int sum)
{
    int n = v.size();
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < sum+1;j++)
        {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < sum + 1;j++)
        {
            if(v[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - v[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
