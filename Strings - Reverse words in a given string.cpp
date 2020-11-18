//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    string ans = "";
    string tmp_ans = "";
    int i = s.length() - 1;
    while(i >= 0)
    {
        if(s[i] != '.')
            tmp_ans.push_back(s[i]);
        else if(s[i] == '.')
        {
            reverse(tmp_ans.begin(), tmp_ans.end());
            ans = ans + tmp_ans;
            ans = ans + '.';
            tmp_ans.clear();
        }
        i--;
    }
    reverse(tmp_ans.begin(), tmp_ans.end());
    ans = ans + tmp_ans;
    cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    solve(s);
	}
	return 0;
}
