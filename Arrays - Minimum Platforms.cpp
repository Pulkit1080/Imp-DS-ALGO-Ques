//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(int a[], int d[], int n)
{
    int min_platforms = 1;
    int curr_needed_platforms = 1;
    int i = 1;
    int j = 0;
    sort(a, a+n);
    sort(d, d+n);
    while(i < n && j < n)
    {
        if(d[j] < a[i])
        {
            j++;
            curr_needed_platforms--;
        }
        else if(d[j] >= a[i])
        {
            i++;
            curr_needed_platforms++;
        }
        min_platforms = max(min_platforms, curr_needed_platforms);
    }
    cout<<min_platforms<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], d[n];
	    for(int i = 0;i < n;i++)
	        cin>>a[i];
	    for(int i = 0;i < n;i++)
	        cin>>d[i];
	    solve(a, d, n);
	}
	return 0;
}
