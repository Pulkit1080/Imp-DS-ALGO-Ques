//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(long long arr[], long long n)
{
    long long max_idx = n-1;
    long long min_idx = 0;
    long long max_ele = arr[n-1] + 1;
    for(long long i = 0;i < n;i++)
    {
        if(i%2 == 0)
        {
            arr[i] += (arr[max_idx]%max_ele) * max_ele;
            max_idx--;
        }
        else
        {
            arr[i] += (arr[min_idx]%max_ele) * max_ele;
            min_idx++;
        }
    }
    for(long long i = 0;i < n;i++)
        cout<<arr[i]/max_ele<<" ";
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long a[n];
	    for(long long i = 0;i < n;i++)
	        cin>>a[i];
	    solve(a, n);
	}
	return 0;
}
