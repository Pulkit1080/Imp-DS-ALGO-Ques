#include<bits/stdc++.h>
using namespace std;
int dfs(int cost[105][105], int m, int n, int i, int j, int dp[105][105])
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int down = cost[i][j] + dfs(cost, m, n, i+1, j, dp);
    int down_left = cost[i][j] + dfs(cost, m, n, i+1, j-1, dp);
    int down_right = cost[i][j] + dfs(cost, m, n, i+1, j+1, dp);
    if(j == 0 && i < m-1)
        return dp[i][j] = min(down, down_right);
    if(j == n-1 && i < m-1)
        return dp[i][j] = min(down, down_left);
    return dp[i][j] = min(down, min(down_left, down_right));
}
int main()
{
    int m, n;
    cin>>m>>n;
    int cost[105][105];
    int dp[105][105];
    memset(dp, -1, sizeof dp);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>cost[i][j];
        }
    }
    int ans = INT_MAX;
    for(int j = 0;j < n;j++)
    {
        ans = min(ans, dfs(cost, m, n, 0, j, dp));
    }
    cout<<ans;
}
/*
5 5
1 3 1 2 6
9 2 5 4 15
8 9 6 7 1
2 7 1 5 3
8 2 6 1 9
*/
