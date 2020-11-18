#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    stack<char>s;
	    string str;
	    cin>>str;
	    bool ans = true;
	    for(int i = 0;str[i] != '\0';i++)
	    {
	        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
	            s.push(str[i]);
	        else if(str[i] == '}')
	        {
	            if(s.empty() || s.top() != '{')
                {
                    ans = false;
                    break;
                }
                else
                    s.pop();
	        }
	        else if(str[i] == ')')
	        {
	            if(s.empty() || s.top() != '(')
                {
                    ans = false;
                    break;
                }
                else
                    s.pop();
	        }
	        else if(str[i] == ']')
	        {
	            if(s.empty() || s.top() != '[')
                {
                    ans = false;
                    break;
                }
                else
                    s.pop();
	        }
	    }
	    if(!s.empty())
	        ans = false;
	    if(ans)
	        cout<<"balanced"<<endl;
	    else
	        cout<<"not balanced"<<endl;
	}
	return 0;
}
