#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int LIS(int a[],int n)  //  naive
{
    for(int i = 0;i < n;i++)
    {
        dp[i] = 1;
        for(int j = 0;j < i;j++)
        {
            if(a[j] < a[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    int ans = 1;
    for(int i = 0;i < n;i++)
        ans = max(ans,dp[i]);
    return ans;
}
int LIS_Optimised(int a[],int n) //tricky DP + Binary Search
{
    dp[0] = INT_MIN;
    for(int i = 1;i < n+1;i++)
        dp[i] = INT_MAX;
    for(int i = 0;i < n;i++)
    {
        int len = upper_bound(dp,dp + n + 1,a[i]) - dp;
        if(dp[len - 1] < a[i] && a[i] < dp[len])
            dp[len] = a[i];
    }
    int lis = 1;
    for(int i = 1;i < n+1;i++)
        if(dp[i] != INT_MAX)
            lis = i;
    return lis;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        //cout<<LIS(a,n);
        cout<<LIS_Optimised(a,n);
        cout<<endl;
    }
}
/*
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

op: -
6
3
*/
