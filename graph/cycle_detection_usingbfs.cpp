#include <bits/stdc++.h>
using namespace std;
bool bfs(int src, vector<int> adj[], vector<int> &visited)
{
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push({i, node});
            }
            else if (parent != i)
                return true;
        }
    }
    return false;
}
bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited)
{
    visited[node] = true;
    // dfs_visited[node]=true;
    for (auto i : adj[node])

    {
        if (!visited[i])
        {
            if (dfs(i, node, adj, visited))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (bfs(i, adj, visited))
                return true;
        }
    }
    return false;
}
