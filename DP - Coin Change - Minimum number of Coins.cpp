#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n>>sum;
    int coins[n];
    for(int i = 0;i < n;i++)
        cin>>coins[i];
    int dp[n+1][sum+1];
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < sum+1;j++)
        {
            if(j == 0)
                dp[i][j] = 0;
            if(i == 0)
                dp[i][j] = INT_MAX - 1;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < sum+1;j++)
        {
            if(coins[i-1] <= j)
            {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][sum];
}
/*
n
sum
coin[]
3
5
3 2 1
op = 2 i.e (2 + 3)
*/
