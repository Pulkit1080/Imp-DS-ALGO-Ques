//  GFG

#include<bits/stdc++.h>
using namespace std;
void solve(int a[][15], int m, int n)
{
    int startRow = 0;
    int startCol = 0;
    int endRow = m-1;
    int endCol = n-1;
    while(startRow <= endRow && startCol <= endCol)
    {
        //top Row
        for(int i = startCol; i <= endCol; i++)
            cout<<a[startRow][i]<<" ";
        startRow++;
        //right Col
        for(int i = startRow; i <= endRow; i++)
            cout<<a[i][endCol]<<" ";
        endCol--;
        //bottom Row
        if(startRow <= endRow)
        {
            for(int i = endCol; i >= startCol; i--)
                cout<<a[endRow][i]<<" ";
            endRow--;
        }
        //left Col
        if(startCol <= endCol)
        {
            for(int i = endRow; i >= startRow; i--)
                cout<<a[i][startCol]<<" ";
            startCol++;
        }
    }
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin>>m>>n;
	    int a[15][15];
	    for(int i = 0;i < m;i++)
	        for(int j = 0;j < n;j++)
	            cin>>a[i][j];
	    solve(a, m, n);
	}
	return 0;
}
