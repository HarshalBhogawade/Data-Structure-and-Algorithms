#include <bits/stdc++.h>
using namespace std;
bool isCycle(int V, vector<vector<int>> &edges)
{

    // Step 1: convert edge list → adjacency list
    vector<vector<int>> adj(V);
    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Step 2: visited array
    vector<int> vis(V, 0);

    // Step 3: traverse all components
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {

            // BFS with (node, parent)
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;

            while (!q.empty())
            {
                auto [node, parent] = q.front();
                q.pop();

                for (auto &it : adj[node])
                {

                    // if not visited → continue BFS
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push({it, node});
                    }

                    // if visited and not parent → cycle
                    else if (it != parent)
                    {
                        return true;
                    }
                }
            }
        }
    }
//dfs approahc below 
// DFS function: returns true if cycle is found
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        
        vis[node] = 1;

        for(auto &it : adj[node]){
            
            // if not visited → go deeper
            if(!vis[it]){
                if(dfs(it, node, adj, vis)) return true;
            }
            // if visited and not parent → cycle
            else if(it != parent){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Step 1: build adjacency list
        vector<vector<int>> adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: visited array
        vector<int> vis(V, 0);

        // Step 3: check all components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)) return true;
            }
        }

        return false;
    }
    return false; // no cycle found
}
int main()
{
}