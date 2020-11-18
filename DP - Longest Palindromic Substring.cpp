//  GFG

#include<bits/stdc++.h>
using namespace std;
string solve_1(string s)        //  using DP O(n*n) time, O(n*n) space
{
    int n = s.length();
    bool dp[n][n];
    memset(dp, false, sizeof dp);
    int start = 0;
    int maxLength = 1;
    //for length 1
    for(int i = 0;i < n;i++)
    {
        dp[i][i] = true;
    }
    //for length 2
    bool length2 = false;
    //so for -> rzzfmjjpans, ans is zz(1 palindromic subs if size 2) not jj i.e later palindromic subs of size 2
    for(int i = 0;i < n-1;i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true;
            if(!length2)
            {
                start = i;
                maxLength = 2;
                length2 = true;
            }
        }
    }
    //for length greater than equal to 3
    for(int k = 3;k <= n;k++)
    {
        for(int i = 0;i <= n-k;i++)
        {
            int j = i + k - 1;
            if(s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                if(k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}
int expandFromMiddle(string str, int s, int e)
{
    while(s >= 0 && e < str.length() && str[s] == str[e])
    {
        s--;
        e++;
    }
    s++;    //due to extra 1 iteration done that should be reversed for correct values
    e--;
    return e - s + 1;
}
string solve_2(string s)        //  using DP O(n*n) time, O(1) space
{
    int start = 0;
    int maxLen = 1;
    for(int i = 0;i < s.length();i++)
    {
        int len1 = expandFromMiddle(s, i, i);   //to handle cases like "racecar" i.e no match for e req(odd palindrome)
        int len2 = expandFromMiddle(s, i, i+1); //to handle cases like "aaaabbaa" i.e match req for b(even palindrome)
        int len = max(len1, len2);
        if(len > maxLen)
        {
            start = i - ((len-1)/2);
            maxLen = len;
        }
    }
    return s.substr(start, maxLen);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<solve_2(s)<<endl;
	}
	return 0;
}
