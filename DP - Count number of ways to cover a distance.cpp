//GFG

#include<bits/stdc++.h>
using namespace std;
int solve_1(int n)      //recursion
{
    if(n == 0 || n == 1)
        return 1;
    if(n == 2)
        return 2;
    return solve_1(n-1) + solve_1(n-2) + solve_1(n-3);
}
int solve_2(int n)      //DP
{
    int dp[n+1];
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < n+1;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    //cout<<solve_1(n);
	    cout<<solve_2(n);
	    cout<<endl<<endl;
	}
	return 0;
}
