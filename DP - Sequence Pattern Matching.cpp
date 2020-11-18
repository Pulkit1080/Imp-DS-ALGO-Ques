#include<bits/stdc++.h>
using namespace std;
int L_C_S(string X,string Y,int m,int n)
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
int main()
{
    string X,Y;
    cin>>X>>Y;
    int lcs = L_C_S(X,Y,X.length(),Y.length());
    if(lcs == X.length() || lcs == Y.length())
        cout<<"True";
    else
        cout<<"False";
}
/*
AXY
ADXCPY
*/
