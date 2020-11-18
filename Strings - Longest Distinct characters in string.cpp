//  GFG

#include<bits/stdc++.h>
using namespace std;
int solve(string s)     //Sliding Window
{
    int lastOcc[256];
    memset(lastOcc, -1, sizeof lastOcc);
    int curr_len = 0;
    int max_len = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(lastOcc[s[i]] == -1 || i - curr_len > lastOcc[s[i]])
            curr_len++;
        else
            curr_len = i - lastOcc[s[i]];
        lastOcc[s[i]] = i;
        max_len = max(max_len, curr_len);
    }
    return max_len;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<solve(s)<<endl;
	}
	return 0;
}
