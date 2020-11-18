//Sliding Window

#include<bits/stdc++.h>
using namespace std;
void solve(vector<long long>v,int sum)
{
    int curr_sum = 0;
    int start = 0;
    for(int end = 0;end < v.size();end++)
    {
        if(curr_sum < sum)
            curr_sum += v[end];

        while(start <= end && curr_sum > sum)
        {
            curr_sum -= v[start];
            start++;
        }
        if(curr_sum == sum)
        {
            cout<<start+1<<" "<<end+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        vector<long long>v(n);
        for(int i = 0;i < n;i++)
        {
            long long x;
            cin>>x;
            v[i] = x;
        }
        solve(v,sum);
    }
	return 0;
}
/*
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
*/
