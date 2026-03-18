#include <bits/stdc++.h>
using namespace std;

//tc : O(N^2) if considered for building list otherwise O(V + E)
//sc : O(3N)
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
{//dfs traverssal

    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            dfs(it, vis, adj);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    // build adjecny list
    int n = isConnected.size();

    //create adjency list from the given matrix 
    vector<vector<int>> adj(n);
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    //create visited list to do traverse of provinces
    int start = 0;
    vector<int> vis(n);
    int cnt = 0;

    //traverse every unvisited province
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            vis[i] = 1;
            dfs(i, vis, adj);
        }
    }

    return cnt;
}
int main()
{
}