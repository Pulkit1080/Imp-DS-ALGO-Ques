//  GFG

#include<bits/stdc++.h>
using namespace std;
int solve(int a[], int n)
{
    int maxi[n];
    maxi[0] = a[0];
    for(int i = 1;i < n;i++)
        maxi[i] = max(maxi[i-1], a[i]);

    int mini[n];
    mini[n-1] = a[n-1];
    for(int i = n-2;i >= 0;i--)
        mini[i] = min(mini[i+1], a[i]);
    for(int i = 1;i < n-1;i++)
    {
        if(maxi[i-1] <= a[i] && a[i] <= mini[i+1])
            return a[i];
    }
    return -1;
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
