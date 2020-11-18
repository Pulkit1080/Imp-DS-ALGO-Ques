//GFG

class Solution
{
	public:
	int maxSumIS(int arr[], int n)  //Similar to LIS
	{
	    int maxSIS[n];
	    for(int i = 0;i < n;i++)
	        maxSIS[i] = arr[i];

	    for(int i = 1;i < n;i++)
	    {
	        int maxi = 0;
	        for(int j = 0;j < i;j++)
	        {
	            if(arr[j] < arr[i] && maxSIS[j] > maxi)
	                maxi = maxSIS[j];
	        }
	        maxSIS[i] += maxi;
	    }
	    int maxi = arr[0];
	    for(int i = 1;i < n;i++)
	    {
	        if(maxSIS[i] > maxi)
	            maxi = maxSIS[i];
	    }
	    return maxi;
	}
};
