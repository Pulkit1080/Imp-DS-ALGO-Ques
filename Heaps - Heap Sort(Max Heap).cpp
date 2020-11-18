//      GFG

/*
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends

void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// The functions should be written in a way that array become sorted
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[].
// n is size of heap. This function  is used in above heapSort()

*/
void heapify(int arr[], int n, int idx)
{
    int left = 2*idx;
    int right = 2*idx + 1;
    int min_idx = idx;
    if(left < n && arr[left] > arr[min_idx])
        min_idx = left;
    if(right < n && arr[right] > arr[min_idx])
        min_idx = right;
    if(idx != min_idx)
    {
        swap(arr[min_idx], arr[idx]);
        heapify(arr, n, min_idx);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i = (n-1)/2; i >= 0;i--)
    {
        heapify(arr, n, i);
    }
}
