//  GFG

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void rev(ll a[], ll s, ll e)
{
    while(s < e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}
void solve(ll a[], ll n, ll k)
{
    for(ll i = 0;i < n;i += k)
    {
        if(i + k < n)
            rev(a, i, i+k-1);
        else
            rev(a, i, n-1);
    }
    for(ll i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    ll n, k;
	    cin>>n>>k;
	    ll a[n];
	    for(ll i = 0;i < n;i++)
	        cin>>a[i];
	    solve(a, n, k);
	}
	return 0;
}
