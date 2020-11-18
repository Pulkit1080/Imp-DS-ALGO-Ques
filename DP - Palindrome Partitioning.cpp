//INTERVIEW BIT
int dp[505][505];
bool isPalindrome(string s,int i,int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j)
{
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(isPalindrome(s,i,j))
        return 0;
    int ans = INT_MAX;
    for(int k = i;k < j;k++)
    {
        int left,right;
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = solve(s,i,k);
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = solve(s,k+1,j);
        int tmp_ans = 1 + left + right;
        ans = min(ans, tmp_ans);
    }
    return dp[i][j] = ans;
}
int Solution::minCut(string A)
{
    memset(dp,-1,sizeof dp);
    return solve(A,0,A.length()-1);
}


