//  GFG

#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void solve(string s, int i)
{
    if(s[i] == '\0')
    {
        ans.push_back(s);
        return;
    }
    for(int j = i;s[j] != '\0';j++)
    {
        swap(s[i], s[j]);
        solve(s, i+1);
        swap(s[i], s[j]);
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    solve(s, 0);
	    sort(ans.begin(), ans.end());
	    for(string s:ans)
	        cout<<s<<" ";
	    cout<<endl;
	    ans.clear();
	}
	return 0;
}
