//LEETCODE

class Solution
{
public:
    int DFS(vector<vector<int>>& matrix, int y, int x, int val, vector<vector<int>>& dp)
    {
        if(y < 0 || y >= matrix.size() || x <0 || x >= matrix[0].size())
            return 0;
        if(matrix[y][x] > val)
        {
            if(dp[y][x] != 0)
                return dp[y][x]; //if this path has been searched
            int a = DFS(matrix, y, x+1,matrix[y][x], dp);
            int b = DFS(matrix, y, x-1,matrix[y][x], dp);
            int c = DFS(matrix, y+1, x,matrix[y][x], dp);
            int d = DFS(matrix, y-1, x,matrix[y][x], dp);
            dp[y][x] = 1 + max(a, max(b,max(c, d)));    //Replace 1 by Matrix[i][j] if sum of path is needed
            return dp[y][x];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if(matrix.size() == 0) return 0;
        int Max = 0;
        vector<int> temp(matrix[0].size(),0);
        vector<vector<int>> dp(matrix.size(), temp);
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                Max = max(DFS(matrix, i, j, INT_MIN, dp), Max);
        return Max;
    }
};
