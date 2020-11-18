#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long dividend, divisor;
    cin>>dividend>>divisor;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1:1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long quotient = 0, temp = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(temp + (divisor << i) <= dividend)
        {
            temp += divisor << i;
            quotient = quotient | (1LL << i);
        }
    }
    cout<<sign * quotient;
}
