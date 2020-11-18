#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;
    int arr[100][100];
    int psa[100][100];
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin>>arr[i][j];
    cout<<endl;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int tl = (i+1)*(j+1);
            int br = (n-i)*(n-j);
            sum += arr[i][j] * (tl*br);
        }
    }
    cout<<sum;
    return 0;
}



