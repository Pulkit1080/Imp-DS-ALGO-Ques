//GFG

#include<bits/stdc++.h>
using namespace std;
int solve(int a[], int n)
{
    int inc = a[0];
    int exc = 0;
    for(int i = 1;i < n;i++)
    {
        int new_inc = exc + a[i];
        int new_exc = max(inc, exc);
        inc = new_inc;
        exc = new_exc;
    }
    return max(inc, exc);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0;i < n;i++)
	        cin>>a[i];
	    cout<<solve(a, n)<<endl;
	}
	return 0;
}
/*
2
6
5 5 10 100 10 5
3
1 2 3
*/
