//GFG

class Solution{

	public:
	int minDiffernce(int arr[], int n)
	{
	    // Your code goes here
	    int sum = accumulate(arr,arr + n,0);
	    bool dp[n+1][sum+1];
	    for(int i = 0;i < n+1;i++)
	    {
	        for(int j = 0;j < sum+1;j++)
	        {
	            if(i == 0)
	                dp[i][j] = false;
	            if(j == 0)
	                dp[i][j] = true;
	        }
	    }
	    for(int i = 1;i < n+1;i++)
	    {
	        for(int j = 1;j < sum+1;j++)
	        {
	            if(arr[i-1] <= j)
	                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    vector<int>pv;
	    for(int j = 0;j <= sum/2;j++)
	        if(dp[n][j] == true)
	            pv.push_back(j);
	    int val = INT_MAX;
	    for(int i = 0;i < pv.size();i++)
	    {
	        int tmp = sum - 2*pv[i];
	        val = min(val,tmp);
	    }
	    return val;
	}
};
