#include<bits/stdc++.h>
using namespace std;
void solve_1(int a[], int n)        //  O(n) time, O(n) space
{
    int smallerAtLeft[n];
    smallerAtLeft[0] = -1;
    int smallNum = 0;
    for(int i = 1;i < n;i++)
    {
        if(a[i] <= a[smallNum])
        {
            smallNum = i;
            smallerAtLeft[i] = -1;
        }
        else
        {
            smallerAtLeft[i] = smallNum;
        }
    }

    int greaterAtRight[n];
    greaterAtRight[n-1] = -1;
    int greatNum = n-1;
    for(int i = n-2;i >= 0;i--)
    {
        if(a[i] >= a[greatNum])
        {
            greatNum = i;
            greaterAtRight[i] = -1;
        }
        else
        {
            greaterAtRight[i] = greatNum;
        }
    }
    for(int i = 0;i < n;i++)
    {
        if(smallerAtLeft[i] != -1 && greaterAtRight[i] != -1)
        {
            cout<<a[smallerAtLeft[i]]<<" "<<a[i]<<" "<<a[greaterAtRight[i]];
            break;
        }
    }
}
void solve_2(int a[], int n)        //  O(n) time, O(1) space
{
    int curr_min = a[0];
    int seq_min = a[0];
    int seq_middle = INT_MIN;
    int seq = 1;
    for(int i = 1;i < n;i++)
    {
        if(a[i] == curr_min)
            continue;
        else if(a[i] < curr_min)
        {
            curr_min = a[i];
            continue;
        }
        else if(a[i] < seq_middle)
        {
            seq_middle = a[i];
            seq_min = curr_min;
        }
        else if(a[i] > seq_middle)
        {
            seq++;
            if(seq == 3)
            {
                cout<<seq_min<<" "<<seq_middle<<" "<<a[i];
                return;
            }
            seq_min = curr_min;
            seq_middle = a[i];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    //solve_1(a, n);
    solve_2(a, n);
}
/*
7
12 11 10 5 6 2 30
*/
