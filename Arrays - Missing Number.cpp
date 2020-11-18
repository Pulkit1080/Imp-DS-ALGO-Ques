//LEETCODE

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = 0;
        int i = 0;
        for(int n:nums)
        {
            ans ^= n;
            ans ^= i;
            i++;
        }
        ans ^= i;
        return ans;
    }
};
