#include<bits/stdc++.h>
using namespace std;
class Interval
{
public:
    int start;
    int end;
};
static bool cmp(Interval a, Interval b)
{
    return a.start < b.start;
}
void solve(Interval a[], int n) //O(nlogn) time, O(1) space
{
    sort(a, a+n, cmp);
    int curr = 0;
    for(int i = 1;i < n;i++)
    {
        if(a[curr].end >= a[i].start)
        {
            a[curr].end = max(a[curr].end, a[i].end);
            a[curr].start = min(a[curr].start, a[i].start);
        }
        else
        {
            curr++;
            a[curr] = a[i];
        }
    }
    for(int i = 0;i <= curr; i++)
    {
        cout<<"["<<a[i].start<<","<<a[i].end<<"] ";;
    }
}
int main()
{
    int n;
    cin>>n;
    Interval arr[n];
    for(int i = 0;i < n;i++)
    {
        cin>>arr[i].start>>arr[i].end;
    }
    solve(arr, n);
}
/*
4
1 3
2 4
5 7
6 8
op =
1 4
5 8
*/
