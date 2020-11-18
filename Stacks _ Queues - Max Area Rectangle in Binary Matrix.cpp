#include<bits/stdc++.h>
using namespace std;
int MAH(vector<int>a)
{
    int n = a.size();
    //Calculate NSL
    vector<int>NSL;
    stack<int>nsl;
    nsl.push(0);
    NSL.push_back(-1);
    for(int i = 1;i < n;i++)
    {
        while(!nsl.empty() && a[i] <= a[nsl.top()])
            nsl.pop();
        if(nsl.empty())
            NSL.push_back(-1);
        else
            NSL.push_back(nsl.top());
        nsl.push(i);
    }
    //Calculate NSR;
    vector<int>NSR;
    stack<int>nsr;
    nsr.push(n-1);
    NSR.push_back(n);
    for(int i = n-2;i >= 0;i--)
    {
        while(!nsr.empty() && a[i] <= a[nsr.top()])
            nsr.pop();
        if(nsr.empty())
            NSR.push_back(n);
        else
            NSR.push_back(nsr.top());
        nsr.push(i);
    }
    reverse(NSR.begin(),NSR.end());
    //Calculate height by (NSR - NSL - 1) * a[i]
    int max_ans = INT_MIN;
    for(int i = 0;i < n;i++)
    {
        int ans = (NSR[i] - NSL[i] - 1) * a[i];
        max_ans = max(ans,max_ans);
    }
    return max_ans;
}
int MaxAreaRectangle(vector<vector<int>>mat)
{
    vector<int>v;
    for(int j = 0;j < mat[0].size();j++)        //for first row
        v.push_back(mat[0][j]);
    int mx = MAH(v);
    for(int i = 1;i < mat.size();i++)           //for rest of the rows
    {
        for(int j = 0;j < mat[0].size();j++)
        {
           if(mat[i][j] == 0)
                v[j] = 0;
           else
                v[j] += mat[i][j];
        }
        mx = max(mx,MAH(v));
    }
    return mx;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n,0));
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<MaxAreaRectangle(mat);
    return 0;
}
/*
4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/
