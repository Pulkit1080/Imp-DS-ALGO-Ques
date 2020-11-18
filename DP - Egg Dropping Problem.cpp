#include<bits/stdc++.h>
using namespace std;
int dp[11][51];
int solve(int n,int k)
{
    if(n == 1 || k == 0 || k == 1)
        return k;
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = INT_MAX;
    for(int m = 1;m <= k;m++)
    {
        int low,high;
        if(dp[n-1][m-1] != -1)
            low = dp[n-1][m-1];
        else
            dp[n-1][m-1] = low = solve(n-1,m-1);
        if(dp[n][k-m] != -1)
            high = dp[n][k-m];
        else
            dp[n][k-m] = high = solve(n,k-m);

        int tmp_ans = 1 + max(low,high);
        ans = min(ans,tmp_ans);
    }
    return dp[n][k] = ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
}
/*
2
2 10
3 5
*/
