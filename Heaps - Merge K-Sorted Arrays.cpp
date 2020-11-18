//  GFG

typedef pair<int, pair<int,int>> node;
int *mergeKArrays(int arr[][N], int k)
{
    //code here
    priority_queue<node, vector<node>, greater<node>>pq;
    int*res = new int[k * k];
    int j = 0;
    for(int i = 0;i < k;i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        int value = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        res[j++] = value;
        if(y < k-1)
        {
            pq.push({arr[x][y+1],{x, y+1}});
        }
    }
    return res;
}
