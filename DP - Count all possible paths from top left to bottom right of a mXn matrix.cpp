//GFG

#include<bits/stdc++.h>
using namespace std;
int solve_1(int m, int n)       //Using Recursion
{
    if(m == 1 || n == 1)
        return 1;
    return solve_1(m-1, n) + solve_1(m, n-1);
}
long long solve_2(int m, int n)       //Using DP
{
    long long dp[m+1][n+1];
    for(long long i = 1;i < m+1;i++)
    {
        for(long long j = 1;j < n+1;j++)
        {
            if(i == 1 || j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
        }
    }
    return dp[m][n];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    //cout<<solve_1(m, n);
	    cout<<solve_2(m, n);
	    cout<<endl;
	}
	return 0;
}
