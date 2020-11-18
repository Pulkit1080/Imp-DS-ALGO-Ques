//GFG

#include<bits/stdc++.h>
using namespace std;
int solve_1(int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        if(n&1)
            return count;
        n >>= 1;
    }
    return count;
}
int solve_2(int n)
{
    if(n == 0)
        return 0;
    int mask = ~n + 1;            //2s complement
    return log2(n & mask) + 1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    //cout<<solve_1(n);
	    cout<<solve_2(n);
	    cout<<endl;
	}
	return 0;
}
