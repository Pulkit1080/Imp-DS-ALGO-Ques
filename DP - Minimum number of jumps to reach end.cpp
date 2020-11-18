//GFG

#include<bits/stdc++.h>
using namespace std;
int solve_1(int a[], int n)     //Recursive Approach O(n^n) time O(1) space
{
    if(n == 1)
        return 0;
    int final_res = INT_MAX;
    for(int i = n-2; i >= 0; i--)
    {
        if(i + a[i] >= n-1)
        {
            int sub_res = solve_1(a, i+1);
            if(sub_res != INT_MAX)
                final_res = min(final_res, sub_res + 1);
        }
    }
    return final_res;
}
int solve_2(int a[], int n)     //DP Approach O(n^2) time O(n) space
{
    int jumps[n];
    if (n == 0 || a[0] == 0)
        return INT_MAX;
    for(int i = 0;i < n;i++)
        jumps[i] = INT_MAX;
    jumps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= j + a[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
int solve_3(int a[], int n)     //Special Approach O(n) time O(1) space
{
    if(n <= 1)
        return 0;
    if(a[0] == 0)
        return -1;
    int jumps = 1;
    int maxReachable = a[0];
    int steps = a[0];
    for(int i = 1;i < n;i++)
    {
        if(i == n-1)
            return jumps;
        maxReachable = max(maxReachable, i + a[i]);
        steps--;
        if(steps == 0)
        {
            jumps++;
            if(i >= maxReachable)
                return -1;
            steps = maxReachable - i;
        }
    }
    return -1;
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
	    {
	        cin>>a[i];
	    }
	    //int ans = solve_1(a, n);
	    //int ans = solve_2(a, n);
	    int ans = solve_3(a, n);
	    ans == INT_MAX?cout<<-1:cout<<ans;
	    cout<<endl;
	}
	return 0;
}
/*
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
*/
