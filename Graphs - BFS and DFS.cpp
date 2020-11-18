#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int>*l;
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src)
    {
        map<int, bool>visited;
        queue<int>q;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(int nbr:l[temp])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfs_helper(int src, map<int, bool>&visited)
    {
        cout<<src<<" ";
        visited[src] = true;
        for(int nbr:l[src])
        {
            if(!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }
    void dfs(int src)
    {
        map<int, bool>visited;
        //mark all as not visited
        for(int i = 0;i < V;i++)
        {
            visited[i] = false;
        }
        dfs_helper(src, visited);
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    //g.dfs(0);
}
