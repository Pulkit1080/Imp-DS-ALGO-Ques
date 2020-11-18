#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int mcm(int a[],int i,int j)
{
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int k = i;k < j;k++)
    {
        int tmp_ans = mcm(a,i,k) + mcm(a,k+1,j) + a[i-1] * a[k] * a[j];
        ans = min(ans,tmp_ans);
    }
    /*
    for(int k = i + 1;k <= j;k++)
    {
        int tmp_ans = mcm(a,i,k - 1) + mcm(a,k,j) + a[i] * a[k] * a[j+1];
        ans = min(ans,tmp_ans);
    }
    */
    return dp[i][j] = ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int a[] = {40,20,30,10,30};
    int n = 5;
    cout<<mcm(a,1,n - 1);
    //cout<<mcm(a,0,n-2);
}
