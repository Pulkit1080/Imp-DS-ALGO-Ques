//  LEETCODE --> Only one Transaction allowed

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0;i < prices.size();i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i] - minPrice);
        }
        return maxProfit;
    }
};


//  GFG     -->     Multiple Transactions allowed   (Valley Peak approach)

//for printing index to gain max profit

#include<bits/stdc++.h>
using namespace std;
void solve(int a[], int n)
{
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        if(a[i] > a[i-1])
        {
            ans++;
            cout<<"("<<i-1<<" ";
            while(i < n)
            {
                if(a[i-1] < a[i])
                    i++;
                else
                    break;
            }
            cout<<i-1<<") ";
        }
    }
    if(ans == 0)
        cout<<"No Profit";
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
	    solve(a, n);
	}
	return 0;
}


//For printing max profit ONLY

#include<bits/stdc++.h>
using namespace std;
int solve(int a[], int n)
{
    int maxProfit = 0;
    for(int i = 1;i < n;i++)
    {
        if(a[i] > a[i-1])
            maxProfit += a[i] - a[i-1];
    }
    return maxProfit;
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


