#include<bits/stdc++.h>
using namespace std;
int solve1(int l,int a,int b,int c)     //For 3 pieces
{
    int dp[l+1];
    memset(dp,-1,sizeof dp);
    dp[0] = 0;
    for(int i = 0;i < l+1;i++)
    {
        if(dp[i] == -1)
            continue;
        if(i + a <= l)
            dp[i+a] = max(dp[i+a],dp[i] + 1);
        if(i + b <= l)
            dp[i+b] = max(dp[i+b],dp[i] + 1);
        if(i + c <= l)
            dp[i+c] = max(dp[i+c],dp[i] + 1);
    }
    return dp[l];
}
int solve2(int n,int a,int b,int c)     //Generalization
{
    int len[3];
    len[0] = a;
    len[1] = b;
    len[2] = c;
    sort(len,len+3);
    int dp[3][n+1];
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < n+1;j++)
        {
            if(j == 0)
                dp[i][j] = 0;
            else if(i == 0)
            {
                if(j%len[i] == 0)
                    dp[i][j] = j/len[i];
                else
                    dp[i][j] = 0;
            }
        }
    }
    for(int i = 1;i < 3;i++)
    {
        for(int j = 1;j < n+1;j++)
        {
            if(len[i] > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                if(dp[i-1][j] == 0 && dp[i][j - len[i]] == 0 && j-len[i] != 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = max(dp[i-1][j] , 1 + dp[i][j - len[i]]);
            }
        }
    }
    return dp[2][n];
}
int main()
{
    int len,a,b,c;
    cin>>len;
    cin>>a>>b>>c;
    //cout<<solve1(len,a,b,c);
    cout<<solve2(len,a,b,c);
    return 0;
}
/*
7
5 5 2
op = 2
*/
