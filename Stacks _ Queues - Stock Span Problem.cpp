#include<bits/stdc++.h>
using namespace std;
void stockSpan(int prices[], int span[], int n)
{
    stack<int>s;
    s.push(0);
    span[0] = 1;
    for(int i = 1;i < n;i++)
    {
        while(!s.empty() && prices[i] >= prices[s.top()])
            s.pop();
        if(s.empty())
            span[i] = i + 1;
        else
            span[i] = i - s.top();
        s.push(i);
    }
}
int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75 ,85};
    int n = 7;
    int span[1000] = {0};
    stockSpan(prices, span, n);
    for(int i = 0;i < n;i++)
    {
        cout<<span[i]<<" ";
    }
}
