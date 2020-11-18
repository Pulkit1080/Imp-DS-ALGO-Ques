#include<bits/stdc++.h>
using namespace std;
int Count_of_Subset_Sum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i = 0;i < n+1;i++)
    {
        for(int j = 0;j < sum+1;j++)
        {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
    for(int i = 1;i < n+1;i++)
    {
        for(int j = 1;j < sum+1;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int arr[] = {2,3,5,6,8,10};
    int n = 6;
    int sum = 10;
    cout<<Count_of_Subset_Sum(arr,n,sum);
}
