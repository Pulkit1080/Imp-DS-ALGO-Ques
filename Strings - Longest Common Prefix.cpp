//  GFG

#include<bits/stdc++.h>
using namespace std;
string match(string a, string b)
{
    int i = 0;
    string ans;
    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] == b[i])
        {
            ans.push_back(a[i]);
        }
        else
            break;
        i++;
    }
    return ans;
}
void solve_1(vector<string>v)   //string matching ->normal ->O(n*m)   i.e no of string and their max size
{
    string main = v[0];
    for(int i = 0;i < v.size();i++)
    {
        main = match(main, v[i]);
    }
    if(main.length() == 0)
        cout<<-1<<endl;
    else
        cout<<main<<endl;
}
void solve_2(vector<string>v)   //Character matching ->better ->O(n*m) i.e better for large n
{
    int minLen = v[0].length();
    for(int i = 1;i < v.size();i++)
    {
        int curr_len =  v[i].length();
        minLen = min(minLen, curr_len);
    }
    string ans;
    for(int i = 0;i < minLen;i++)
    {
        char ch = v[0][i];
        bool matched = true;
        for(int j = 1;j < v.size();j++)
        {
            if(v[j][i] != ch)
            {
                matched = false;
                break;
            }
        }
        if(matched)
            ans += ch;
        else
            break;
    }
    if(ans.length() == 0)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    vector<string>v;
	    for(int i = 0;i < n;i++)
	    {
	        cin>>s;
	        v.push_back(s);
	    }
	    solve_2(v);
	}
	return 0;
}
