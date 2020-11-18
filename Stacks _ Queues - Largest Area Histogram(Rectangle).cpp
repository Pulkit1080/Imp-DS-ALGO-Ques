#include<bits/stdc++.h>
using namespace std;
int LAH(int a[], int n)
{
    //Calculating NSL array
    vector<int>nsl;
    stack<int>nsl_stack;
    nsl.push_back(-1);
    nsl_stack.push(0);
    for(int i = 1;i < n;i++)
    {
        while(!nsl_stack.empty() && a[i] <= a[nsl_stack.top()])
            nsl_stack.pop();
        if(nsl_stack.empty())
            nsl.push_back(-1);
        else
            nsl.push_back(nsl_stack.top());
        nsl_stack.push(i);
    }
    //Calculating NSR array
    vector<int>nsr;
    stack<int>nsr_stack;
    nsr.push_back(n);
    nsl_stack.push(n-1);
    for(int i = n-2;i >= 0;i--)
    {
        while(!nsr_stack.empty() && a[i] <= a[nsr_stack.top()])
            nsr_stack.pop();
        if(nsr_stack.empty())
            nsr.push_back(n);
        else
            nsr.push_back(nsr_stack.top());
        nsr_stack.push(i);
    }
    reverse(nsr.begin(), nsr.end());
    //Calculating max area
    int maxArea = 0;
    for(int i = 0;i < n;i++)
    {
        int area = (nsr[i] - nsl[i] - 1) * a[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    cout<<LAH(arr, n);
}
