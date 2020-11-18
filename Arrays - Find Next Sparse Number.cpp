//GFG

#include<bits/stdc++.h>
using namespace std;
bool checkSparse(int n)
{
    int last = 0;
    while(n > 0)
    {
        if(n&1 && last)
            return false;
        last = n&1;
        n >>= 1;
    }
    return true;
}
int solve_1(int n)
{
    if(n == 0 || n == 1)
        return n;
    int ans;
    while(1)
    {
        if(checkSparse(n))
        {
            ans = n;
            break;
        }
        else
            n++;
    }
    return ans;
}
int solve_2(int n)
{
    int last_pos_changed = 0;
    vector<int>bin_form;    //bin_form[0] stores lsb and so on
    while(n > 0)
    {
        bin_form.push_back(n&1);
        n >>= 1;
    }
    bin_form.push_back(0);  //to take care of consecutive 1s at the end
    for(int i = 1;i < bin_form.size() - 1;i++)
    {
        if(bin_form[i] == 1 && bin_form[i-1] == 1 && bin_form[i+1] != 1)
        {
            bin_form[i+1] = 1;
            for(int j = last_pos_changed; j <= i;j++)
                bin_form[j] = 0;
            last_pos_changed = i + 1;
        }
    }
    int ans = 0;
    for(int i = 0;i < bin_form.size(); i++)
    {
        ans += bin_form[i] * (1 << i);
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
	    //cout<<solve_1(n)<<endl;
	    cout<<solve_2(n)<<endl;
	}
	return 0;
}
