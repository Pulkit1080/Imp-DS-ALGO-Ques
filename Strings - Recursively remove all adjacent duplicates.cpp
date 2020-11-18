//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(string str)
{
    bool flag = true;
    while(flag && str.length() > 0)
    {
        flag = false;
        int i = 0;
        int n = str.length();
        stack<char>s;
        while(i < n)
        {
            if(s.empty() || s.top() != str[i])
                s.push(str[i]);
            else
            {
                flag = true;
                while(i < n && s.top() == str[i])
                    i++;
                s.pop();
                s.push(str[i]);
            }
            i++;
        }
        str.clear();
        while(!s.empty())
        {
            str.push_back(s.top());
            s.pop();
        }
        reverse(str.begin(), str.end());
    }
    cout<<str<<endl;
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
