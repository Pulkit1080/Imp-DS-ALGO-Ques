//GFG
//operations -> n/2 or n+1 or n-1

#include <iostream>
using namespace std;
int countSteps(int n)
{
    int count = 0;
    while (n > 1) {
        count++;

        // num even, divide by 2
        if (n % 2 == 0)
            n /= 2;

        // num odd, n%4 == 1, decrement by 1
        else if (n % 4 == 1)
            n -= 1;

        // num odd, n%4 == 3, increment by 1
        else
            n += 1;
    }

    return count;
}


int main()
{
    int n;
    cin>>n;
    cout << countSteps(n);
    return 0;
}
