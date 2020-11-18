#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n,int diff)
{
    int sum = accumulate(arr,arr+n,0);
    int sum_to_find = (sum + diff)/2;
    int dp[n+1][sum_to_find+1];
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < sum_to_find+1;j++)
        {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < sum_to_find+1;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum_to_find];
}
int main()
{
    int arr[] = {1,1,2,3};
    int diff = 1;
    int n = 4;
    cout<<solve(arr,n,diff);
    return 0;
}
