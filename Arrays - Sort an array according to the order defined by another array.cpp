//GFG

#include<bits/stdc++.h>
using namespace std;
void solve_1(int a1[], int a2[], int m, int n)    //for rest elements in sorted order
{
    map<int, int>mp;
    for(int i = 0;i < m;i++)
        mp[a1[i]]++;
    for(int i = 0;i < n;i++)
    {
        while(mp[a2[i]] > 0)
        {
            cout<<a2[i]<<" ";
            mp[a2[i]]--;
        }
    }
    for(auto p:mp)
    {
        int times = p.second;
        while(times--)
            cout<<p.first<<" ";
    }
    cout<<endl;
}
void solve_2(int a1[], int a2[], int m, int n)    //for rest elements in same order
{
    unordered_map<int, int>mp;
    for(int i = 0;i < m;i++)
        mp[a1[i]]++;
    for(int i = 0;i < n;i++)
    {
        while(mp[a2[i]] > 0)
        {
            cout<<a2[i]<<" ";
            mp[a2[i]]--;
        }
    }
    for(int i = 0;i < m;i++)
    {
        if(mp[a1[i]] > 0)
            cout<<a1[i]<<" ";
    }
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>m>>n;
	    int a1[m], a2[n];
	    for(int i = 0;i < m;i++)
	        cin>>a1[i];
	    for(int i = 0;i < n;i++)
            cin>>a2[i];
        solve_1(a1, a2, m, n);
        //solve_2(a1, a2, m, n);
	}
	return 0;
}
