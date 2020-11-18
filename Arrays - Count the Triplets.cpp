//  GFG

int countTriplet_1(int arr[], int n)
{
    // Your code goes here
    if(n < 3)
        return 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, arr[i]);
    int mp[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int ans = 0;
    //  4 Cases
    ans += ( (mp[0])*(mp[0] - 1)*(mp[0] - 2) )/6;     //0, 0, 0

    for(int i = 1;i <= maxi;i++)                      //0, x, x
        ans += ( (mp[0])*(mp[i])*(mp[i] - 1) )/2;

    for(int i = 1;2*i <= maxi;i++)                    //x, x, 2x
        ans += ( (mp[i])*(mp[i] - 1)*(mp[2*i]) )/2;

    for(int i = 1;i <= maxi;i++)                      //x, y, x+y
    {
        for(int j = i+1;i+j <= maxi; j++)
        {
            ans += mp[i] * mp[j] * mp[i+j];
        }
    }
    return ans;
}

int countTriplet_2(int arr[], int n)
{
    if(n < 3)
        return 0;
    int cnt = 0;
    sort(arr, arr+n);
    for(int i = 0;i < n-2;i++)
    {
        int j = i+1;
        int k = i+2;
        while(k < n)
        {
            if(arr[i] + arr[j] == arr[k])
            {
                cnt++;
                j++;
                k++;
            }
            else if(arr[i] + arr[j] < arr[k])
            {
                j++;
            }
            else if(arr[i] + arr[j] > arr[k])
            {
                k++;
            }
        }
    }
    return cnt;
}
