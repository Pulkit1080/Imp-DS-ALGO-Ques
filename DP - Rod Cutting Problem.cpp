#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,length;
    cin>>n>>length;
    int len[n];
    int price[n];
    for(int i = 0;i < n;i++)
        cin>>len[i];
    for(int i = 0;i < n;i++)
        cin>>price[i];
    int dp[n+1][length+1];
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < length+1;j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < length+1;j++)
        {
            if(len[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j - len[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][length];
}
/*
length
price[]
8
1 5 8 9 10 17 17 20
op = 22

n
length
allowed lengths[]
price[]
4
9
3 5 1 2
8 10 1 5
op = 24
*/
