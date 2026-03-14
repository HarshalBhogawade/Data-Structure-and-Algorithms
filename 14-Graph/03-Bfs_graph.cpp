#include <bits/stdc++.h>
using namespace std;

/*
    BFS Traversal of a Graph (Adjacency List)

    Time Complexity: O(V + E)
    - V → each vertex is visited once
    - E → each edge is explored once

    Space Complexity: O(V)
    - visited array → O(V)
    - queue (worst case) → O(V)
    - answer vector → O(V)
*/

vector<int> bfsTraversal(vector<vector<int>> &adj)
{
    int n = adj.size();          // number of vertices
    vector<int> vis(n, 0);       // visited array
    vector<int> ans;             // stores BFS traversal
    queue<int> q;                // queue for BFS

    int start = 0;               // starting node
    q.push(start);
    vis[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // store node in traversal
        ans.push_back(node);

        // traverse neighbours
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;   // n = nodes, m = edges

    vector<vector<int>> adj(n);

    // input edges (undirected graph)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // perform BFS
    vector<int> res = bfsTraversal(adj);

    // print traversal
    for (auto &it : res)
    {
        cout << it << " ";
    }

    return 0;
}