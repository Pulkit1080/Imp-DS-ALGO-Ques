#include<bits/stdc++.h>
using namespace std;

void solve(int a[], int n)
{
    int count_ways[n];
    memset(count_ways, 0, sizeof count_ways);
    for(int i = n-2; i >= 0;i--)
    {
        if(i + a[i] >= n-1)
            count_ways[i]++;
        for(int j = i+1; j < n-1; j++)
        {
            if(i + a[i] >= j && count_ways[j] != -1)
                count_ways[i] += count_ways[j];
        }
        if(count_ways[i] == 0)
            count_ways[i] = -1;
    }

    for(int i = 0;i < n;i++)
        cout<<count_ways[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    solve(a, n);
}
/*
4
3 2 0 1
op
2 1 -1 0

11
1 3 5 8 9 1 0 7 6 8 9
op
52 52 28 16 8 -1 -1 4 2 1 0
*/
