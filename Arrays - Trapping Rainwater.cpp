#include<bits/stdc++.h>
using namespace std;
vector<int>MXR(int a[], int n)
{
    vector<int>mxr(n, a[n-1]);
    for(int i = n-2; i >= 0;i--)
    {
        mxr[i] = max(mxr[i+1], a[i]);
    }
    return mxr;
}
vector<int>MXL(int a[], int n)
{
    vector<int>mxl(n, a[0]);
    for(int i = 1;i < n;i++)
    {
        mxl[i] = max(mxl[i-1], a[i]);
    }
    return mxl;
}
int TRW1(int a[], int n)        //  O(n) space
{
    vector<int>mxr = MXR(a, n);
    vector<int>mxl = MXL(a, n);
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += min(mxr[i], mxl[i]) - a[i];
    }
    return ans;
}
int TRW2(int a[], int n)        //  O(1) space
{
    int ans = 0;
    int lmax = a[0];
    int rmax = a[n-1];
    int i = 0;
    int j = n-1;
    while(i <= j)
    {
        lmax = max(lmax, a[i]);
        rmax = max(rmax, a[j]);
        if(lmax <= rmax)
        {
            ans += (lmax - a[i]);
            i++;
        }
        else
        {
            ans += (rmax - a[j]);
            j--;
        }
    }
    return ans;
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
	    //cout<<TRW1(a, n)<<endl;
	    cout<<TRW2(a, n)<<endl;
	}
	return 0;
}
