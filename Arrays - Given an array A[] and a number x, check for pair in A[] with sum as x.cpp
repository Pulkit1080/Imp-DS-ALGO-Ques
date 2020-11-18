//GFG

//Can also be done in n-logn time in O(1) space using sorting and 2 pointer approach

class Solution{
public:
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x)     // O(n) time, O(n) space
	{
	    map<int, int>mp;
	    for(int i = 0;i < n;i++)
	    {
	        int temp = x - arr[i];
	        if(mp.find(temp) != mp.end())
	            return true;
	        mp[arr[i]] = 1;
	    }
	    return false;
	}
};
