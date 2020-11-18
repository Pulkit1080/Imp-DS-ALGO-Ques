//  GFG

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m)
    {
        int i = n - 1;
        int j = 0;
        while(j < m && i >= 0)
        {
            if(arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
