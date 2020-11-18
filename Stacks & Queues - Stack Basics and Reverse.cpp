#include<bits/stdc++.h>
using namespace std;
class Stack
{
    vector<int>v;
public:
    void push(int d)
    {
        v.push_back(d);
    }
    void pop()
    {
        if(!v.empty())
            v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0;
    }
};
void transfer(stack<int>&s1, stack<int>&s2, int n)
{
    for(int i = 0;i < n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void ReverseStackIterative(stack<int>&s1)   //Using Extra Stack
{
    stack<int>s2;
    int n = s1.size();
    for(int i = 0;i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2 ,s1, n - i - 1);
    }
}
void InsertAtBottom(stack<int>&s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    InsertAtBottom(s , x);
    s.push(data);
}
void ReverseStackRecursion(stack<int>&s1)   //Without extra Stack
{
    if(s1.empty())
        return;
    int x = s1.top();
    s1.pop();
    ReverseStackRecursion(s1);
    InsertAtBottom(s1, x);
}
void printStack(stack<int>s1)
{
    stack<int>s2 = s1;
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;
}
int main()
{
    /*
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    */
    stack<int>s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    //ReverseStackIterative(s);
    ReverseStackRecursion(s);
    printStack(s);
}
