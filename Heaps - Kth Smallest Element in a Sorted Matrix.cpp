#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > customPair;//it will store the value of element and its row and col no
int main()
{
    int arr[][4] =
    {
        {10,20,30,40},
        {15,25,35,45},
        {24,29,37,48},
        {32,37,39,50},
    };
    bool vis[4][4] = {false};
    priority_queue<customPair, vector<customPair>, greater<customPair> >pq;//min heap
    for(int i=0;i<4;i++)
    {
        //push the first row completely in the heap
        pq.push({arr[0][i], {0,i}} );
        vis[0][i] = true;
    }
    int ans = 0;
    int element;
    cin>>element;
    for(int i=0;i<element;i++)
    {
        customPair current = pq.top();
        ans = current.first;
        pq.pop();
        int x = current.second.first;//this holds the row no. of element
        int y = current.second.second;//this holds the col no. of element
        if(x < 3 && !vis[x+1][y])
        {
            pq.push({arr[x+1][y], {x+1,y} });
            vis[x+1][y] = true;
        }
        if(y < 3 && !vis[x][y+1])
        {
            pq.push({arr[x][y+1] , {x,y+1}});
            vis[x][y+1] = true;
        }
    }
    cout<<ans<<endl;
    return 0;
}
