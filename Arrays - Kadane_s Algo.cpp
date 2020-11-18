//  GFG

#include<bits/stdc++.h>
using namespace std;
int kadane(int a[], int n)
{
    int curr_max = a[0];
    int global_max = a[0];
    for(int i = 1;i < n;i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        global_max = max(global_max, curr_max);
    }
    return global_max;
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
	    cout<<kadane(a, n)<<endl;
	}
	return 0;
}
