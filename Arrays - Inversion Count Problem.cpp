//  GFG

#include<bits/stdc++.h>
using namespace std;
long long crossInversions(long long a[], long long temp[], long long s, long long e)
{
    long long i = s;
    long long mid = s + (e-s)/2;
    long long j = mid + 1;
    long long k = s;
    long long count = 0;
    while(i <= mid && j <= e)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
    }
    while(i <= mid)
    {
        temp[k++] = a[i++];
    }
    while(j <= e)
    {
        temp[k++] = a[j++];
    }
    for(long long i = s;i <= e;i++)
        a[i] = temp[i];
    return count;
}
long long inversionCount(long long a[],long long temp[], long long s, long long e)
{
    if(s >= e)
        return 0;
    long long mid = s + (e-s)/2;
    long long x = inversionCount(a, temp, s, mid);
    long long y = inversionCount(a, temp, mid+1, e);
    long long z = crossInversions(a, temp, s, e);
    return x + y + z;
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
	    long long temp[n];
	    cout<<inversionCount(a, temp, 0, n-1)<<endl;
	}
	return 0;
}
