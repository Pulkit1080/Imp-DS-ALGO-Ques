//GFG

#include<bits/stdc++.h>
int equilibriumPoint(long long a[], int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return -1;
    long long leftSum = a[0];
    long long rightSum = accumulate(a, a+n, 0) - a[0];
    for(int i = 1;i < n-1;i++)
    {
        rightSum -= a[i];
        if(leftSum == rightSum)
            return i+1;
        leftSum += a[i];
    }
    return -1;
}
