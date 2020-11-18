//GFG

#include<bits/stdc++.h>
using namespace std;

int countWays_1(int p, int q, int r, int last)        //Recursion
{
    if (p < 0 || q < 0 || r < 0)
        return 0;
    if (p == 1 && q == 0 && r == 0 && last == 0)
        return 1;
    if (p == 0 && q == 1 && r == 0 && last == 1)
        return 1;
    if (p == 0 && q == 0 && r == 1 && last == 2)
        return 1;
    if (last == 0)
        return countWays_1(p-1,q,r,1) + countWays_1(p-1,q,r,2);
    if (last == 1)
        return countWays_1(p,q-1,r,0) + countWays_1(p,q-1,r,2);
    if (last == 2)
        return countWays_1(p,q,r-1,0) + countWays_1(p,q,r-1,1);
}

int dp[100][100][100][3];
int countWays_2(int p, int q, int r, int last)    //DP
{
    if (p < 0 || q < 0 || r < 0)
        return 0;
    if (p == 1 && q == 0 && r == 0 && last == 0)
        return 1;
    if (p == 0 && q == 1 && r == 0 && last == 1)
        return 1;
    if (p == 0 && q == 0 && r == 1 && last == 2)
        return 1;

    if (dp[p][q][r][last] != -1)
        return dp[p][q][r][last];

// if last ball required is P and the number of ways is the sum of number of ways to form sequence with 'p-1' P balls,
// q Q Balls and r R balls ending with Q and R.
    if (last == 0)
       dp[p][q][r][last] = countWays_2(p-1,q,r,1) + countWays_2(p-1,q,r,2);

    // Same as above case for 'q' and 'r'
    else if (last == 1)
       dp[p][q][r][last] = countWays_2(p,q-1,r,0) + countWays_2(p,q-1,r,2);

    else //(last==2)
       dp[p][q][r][last] =  countWays_2(p,q,r-1,0) + countWays_2(p,q,r-1,1);

    return dp[p][q][r][last];
}
int main()
{
    int p, q, r;
    cin>>p>>q>>r;
    /*
    cout<< countWays_1(p, q, r, 0) +  // Last required balls is type P
           countWays_1(p, q, r, 1) +  // Last required balls is type Q
           countWays_1(p, q, r, 2); // Last required balls is type R
    */
    memset(dp, -1, sizeof(dp));
    cout<< countWays_2(p, q, r, 0) +  // Last required balls is type P
           countWays_2(p, q, r, 1) +  // Last required balls is type Q
           countWays_2(p, q, r, 2); // Last required balls is type R

}
/*
1 1 1
*/
