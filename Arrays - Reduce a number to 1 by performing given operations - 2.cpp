//GFG
//operations -> n/3 or n+1 or n-1

#include <iostream>
using namespace std;
int countSteps(int n)
{
    int count = 0;
    while(n > 1)
    {
        if(n%3 == 0)
            n /= 3;
        else if(n%3 == 1)
            n--;
        else
        {
            if(n == 2)
                n--;
            else
                n++;
        }
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    cout<<countSteps(n);
    return 0;
}
