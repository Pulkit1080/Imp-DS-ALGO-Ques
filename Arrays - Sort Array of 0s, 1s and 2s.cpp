//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(int a[], int s, int mid, int e, int n)   //Dutch National Flag Algorithm OR 3-way Partitioning
{
    for(int i = 0;i < n;i++)
    {
        switch(a[mid])
        {
            case 0:swap(a[s++], a[mid++]);
                   break;
            case 1:mid++;
                   break;
            case 2:swap(a[mid], a[e--]);
                   break;
        }
    }
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
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
	    solve(a, 0, 0, n-1, n);
	}
	return 0;
}
