//GFG


class Solution{
public:
    long long findgroups(int arr[], int n)
    {
        // code here
        long long ans = 0;
        long long mp[3];
        mp[0] = mp[1] = mp[2] = 0;
        for(long long i = 0;i < n;i++)
            mp[arr[i]%3]++;
        ans += (mp[0]*(mp[0] - 1))/2;
        ans += mp[1]*mp[2];

        ans += (mp[0]*(mp[0] - 1)*(mp[0]-2))/6;
        ans += (mp[1]*(mp[1] - 1)*(mp[1]-2))/6;
        ans += (mp[2]*(mp[2] - 1)*(mp[2]-2))/6;
        ans += mp[0]*mp[1]*mp[2];
        return ans;
    }
};
