#include<bits/stdc++.h>
using namespace std;
string printlcs(string X,string Y,int m,int n)
{
    int dp[105][105];
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
    int i = m;
    int j = n;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            s = s + X[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        string X,Y;
        cin>>X>>Y;
        cout<<printlcs(X,Y,m,n)<<endl;
    }
}
/*
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
*/
