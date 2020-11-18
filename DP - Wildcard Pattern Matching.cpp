//GFG

int wildCard(string pattern,string str)
{
    int m = str.length();
    int n = pattern.length();
    bool dp[m+1][n+1];
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for(int j = 1;j < n+1;j++)
    {
        if(pattern[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    }
    for(int i = 1;i < m+1;i++)
    {
        for(int j = 1;j < n+1;j++)
        {
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(pattern[j-1] == '*')
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else if(str[i-1] != pattern[j-1])
                dp[i][j] = false;
        }
    }
    return dp[m][n];
}
