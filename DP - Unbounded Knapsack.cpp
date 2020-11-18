#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,W;
    cin>>n>>W;
    int val[n];
    int wt[n];
    for(int i = 0;i < n;i++)
        cin>>val[i];
    for(int i = 0;i < n;i++)
        cin>>wt[i];
    int dp[n+1][W+1];
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < W+1;j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < W+1;j++)
        {
            if(wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i][j - wt[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][W];
}
/*
N
W
val[]
wt[]
4
8
10 70 50 40
1 5 4 3
op = 110
*/
