//GFG

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        // code here
        int lw = 0;
        int rw = 0;
        int bestWin = 0;
        int bestL = 0;
        int curr_zeroes = 0;
        while(rw < n)
        {
            if(curr_zeroes <= m)
            {
                if(arr[rw] == 0)
                    curr_zeroes++;
                rw++;
            }
            if(curr_zeroes > m)
            {
                if(arr[lw] == 0)
                    curr_zeroes--;
                lw++;
            }
            if((bestWin < rw - lw) && (curr_zeroes <= m))
            {
                bestWin = rw - lw;
                bestL = lw;
            }
        }
        //To print positions of number flipped
        for(int i = 0;i < bestWin;i++)
        {
            if(arr[i+bestL] == 0)
                cout<<i+bestL<<" ";
        }
        cout<<endl;
        return bestWin;
    }
};
