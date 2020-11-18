#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int solve(int a[],int i,int j)
{
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    //If we choose left first
    int op_left, op_left_left, op_left_right;
    if(dp[i+2][j] != -1)
        op_left_left = dp[i+2][j];
    else
        dp[i+2][j] = op_left_left = solve(a,i+2,j);
    if(dp[i+1][j-1] != -1)
        op_left_right = dp[i+1][j-1];
    else
        dp[i+1][j-1] = op_left_right = solve(a,i+1,j-1);
    op_left = a[i] + min(op_left_left,op_left_right);

    //If we choose right first
    int op_right, op_right_left, op_right_right;
    if(dp[i+1][j-1] != -1)
        op_right_left = dp[i+1][j-1];
    else
        dp[i+1][j-1] = op_right_left = solve(a,i+1,j-1);
    if(dp[i][j-2] != -1)
        op_right_right = dp[i][j-2];
    else
        dp[i][j-2] = op_right_right = solve(a,i,j-2);
    op_right = a[j] + min(op_right_left, op_right_right);

    int ans = max(op_left, op_right);
    return dp[i][j] = ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        cout<<solve(a,0,n-1)<<endl;
    }
}
/*
2
4
5 3 7 10
4
8 15 3 7

op: -
15
22
*/
