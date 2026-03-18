#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int &nodes, int &edges)
{
    vis[node] = 1;
    nodes++;
    edges += adj[node].size();

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, nodes, edges);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{

    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> vis(n, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int nodes = 0;
            int edgeSum = 0;

            dfs(i, vis, adj, nodes, edgeSum);

            int actualEdges = edgeSum / 2;
            int requiredEdges = nodes * (nodes - 1) / 2;

            if (actualEdges == requiredEdges)
                ans++;
        }
    }

    return ans;
}
int main()
{
}