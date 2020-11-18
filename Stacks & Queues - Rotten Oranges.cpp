//  GFG

#include<bits/stdc++.h>
using namespace std;
int solve(int mat[][105], int r, int c)
{
    int ans = 0;
    queue<pair<int, int>>q;
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            if(mat[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    q.push({-1, -1});
    bool found = false;
    while(!q.empty())
    {
        pair<int, int>curr = q.front();
        //cout<<curr.first<<" "<<curr.second<<endl;
        q.pop();
        if(curr.first == -1 && curr.second == -1)
        {
            found = false;
            if(q.empty())
                break;
            else
                q.push({-1, -1});
        }
        else
        {
            int x = curr.first;
            int y = curr.second;

            //Check bottom
            if(x < r-1 && mat[x+1][y] == 1)
            {
                if(!found)
                {
                    found = true;
                    ans++;
                }
                mat[x+1][y] = 2;
                q.push({x+1, y});
            }
            //Check top
            if(x > 0 && mat[x-1][y] == 1)
            {
                if(!found)
                {
                    found = true;
                    ans++;
                }
                mat[x-1][y] = 2;
                q.push({x-1, y});
            }
            //Check left
            if(y > 0 && mat[x][y-1] == 1)
            {
                if(!found)
                {
                    found = true;
                    ans++;
                }
                mat[x][y-1] = 2;
                q.push({x, y-1});
            }
            //Check right
            if(y < c-1 && mat[x][y+1] == 1)
            {
                if(!found)
                {
                    found = true;
                    ans++;
                }
                mat[x][y+1] = 2;
                q.push({x, y+1});
            }
        }
    }
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            if(mat[i][j] == 1)
                return -1;
        }
    }
    return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int r, c;
	    cin>>r>>c;
	    int mat[105][105];
	    for(int i = 0;i < r;i++)
	    {
	        for(int j = 0;j < c;j++)
	        {
	            cin>>mat[i][j];
	        }
	    }
	    cout<<solve(mat, r ,c)<<endl;
	}
	return 0;
}
/*
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1
*/
