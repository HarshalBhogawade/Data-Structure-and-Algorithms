#include <bits/stdc++.h>
using namespace std;

/*
    DFS Traversal of a Graph (Adjacency List)

    Time Complexity: O(V + E)
    - V → each vertex is visited once
    - E → each edge is explored once

    Space Complexity: O(V)
    - visited array → O(V)
    - recursion stack (worst case) → O(V)
    - answer vector → O(V)
*/

// recursive DFS function
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans)
{
    // mark current node as visited
    vis[node] = 1;

    // store node in traversal result
    ans.push_back(node);

    // traverse all neighbours of current node
    for (auto &it : adj[node])
    {
        // visit neighbour if not visited
        if (!vis[it])
        {
            dfs(it, adj, vis, ans);
        }
    }
}

// wrapper DFS function
vector<int> dfsTraversal(vector<vector<int>> &adj)
{
    int n = adj.size();          // number of vertices
    vector<int> vis(n, 0);       // visited array
    vector<int> ans;             // stores DFS traversal

    int start = 0;               // starting node
    dfs(start, adj, vis, ans);   // call recursive DFS

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

    // perform DFS
    vector<int> res = dfsTraversal(adj);

    // print traversal
    for (auto &it : res)
    {
        cout << it << " ";
    }

    return 0;
}