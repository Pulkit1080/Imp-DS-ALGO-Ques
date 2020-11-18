//GFG

class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int m = s.length();
		    int n = t.length();
		    int dp[m+1][n+1];
		    for(int i = 0;i < m+1;i++)
		    {
		        for(int j = 0;j < n+1;j++)
		        {
		            if(i == 0 && j == 0)
		                dp[i][j] = 0;
		            else if(i == 0)
		                dp[i][j] = dp[i][j-1] + 1;
		            else if(j == 0)
		                dp[i][j] = dp[i-1][j] + 1;
		            else if(s[i-1] == t[j-1])
		                dp[i][j] = dp[i-1][j-1];
		            else
		                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))  + 1;
		        }
		    }
		    return dp[m][n];
		}
};
