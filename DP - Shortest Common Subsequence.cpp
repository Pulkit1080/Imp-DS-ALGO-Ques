#include<bits/stdc++.h>
using namespace std;
int lcs(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];
    for(int i = 0;i < m+1;i++)
    {
        for(int j = 0;j < n+1;j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i = 1;i < m+1;i++)
    {
        for(int j = 1;j < n+1;j++)
        {
            if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int scs(string X,string Y)
{
    int length_of_common_char = lcs(X,Y,X.length(),Y.length());
    int tot_len = X.length() + Y.length();
    return tot_len - length_of_common_char;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string X,Y;
        cin>>X>>Y;
        cout<<scs(X,Y)<<endl;
    }
}
/*
2
abcd xycd
efgh jghi
*/
