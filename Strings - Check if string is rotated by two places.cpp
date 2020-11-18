//  GFG

#include<bits/stdc++.h>
using namespace std;
bool solve(string a, string b)
{
    if(a.length() != b.length())
        return false;
    if(a.length() == 1)
    {
        if(a == b)
            return true;
        else
            return false;
    }
    int n = a.length();
    string first_a;
    first_a.push_back(a[0]);
    first_a.push_back(a[1]);

    string last_a;
    last_a.push_back(a[n-2]);
    last_a.push_back(a[n-1]);
    string new_a_1;
    new_a_1.append(last_a);
    for(int i = 0;i < n-2;i++)
        new_a_1.push_back(a[i]);

    string new_a_2;
    for(int i = 2;i < n;i++)
        new_a_2.push_back(a[i]);
    new_a_2.append(first_a);
    if(b == new_a_1 || b == new_a_2)
        return true;
    return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string a, b;
	    cin>>a>>b;
	    cout<<solve(a, b)<<endl;
	}
	return 0;
}
