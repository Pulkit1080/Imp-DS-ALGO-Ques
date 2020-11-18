//  GFG

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll a[], int n)
{
    ll minCost = 0;
    priority_queue<ll,vector<ll>, greater<ll>>pq;
    for(ll i = 0;i < n;i++)
        pq.push(a[i]);
    while(pq.size() > 1)
    {
        ll least = pq.top();
        pq.pop();
        ll second_least = pq.top();
        pq.pop();
        minCost += least + second_least;
        pq.push(least + second_least);
    }
    return minCost;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll a[n];
	    for(ll i = 0;i < n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<solve(a, n)<<endl;
	}
	return 0;
}
