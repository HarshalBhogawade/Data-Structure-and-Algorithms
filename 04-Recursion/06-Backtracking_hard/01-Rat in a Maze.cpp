#include <bits/stdc++.h>
using namespace std;

/*
    RAT IN A MAZE (Backtracking)

    Time Complexity:
        Worst-case theoretical: O(4^(n*n))
        Practical: Every cell visited once with 4 directions → O(4 * n*n)

    Space Complexity:
        O(n*n) for visited matrix + recursion stack depth
*/

class Solution {

    // Recursive helper to explore all paths
    void solve(int i, int j,
               vector<vector<int>> &grid,
               int n,
               vector<string> &ans,
               string move,
               vector<vector<int>> &vis,
               int di[], int dj[]) 
    {
        // Base case: reached bottom-right cell
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // Direction letters corresponding to di/dj
        string dir = "DLRU";   // Down, Left, Right, Up

        // Try moving in all 4 directions
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            // Check valid movement
            if (nexti >= 0 && nextj >= 0 &&
                nexti < n && nextj < n &&
                !vis[nexti][nextj] && grid[nexti][nextj] == 1) 
            {
                vis[i][j] = 1;   // mark current as visited

                solve(nexti, nextj, grid, n, ans, move + dir[ind], vis, di, dj);

                vis[i][j] = 0;   // backtrack
            }
        }
    }

public:
    // Main API to find all paths
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<string> ans;

        // If start is blocked → no paths
        if (m[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Direction arrays: D, L, R, U
        int di[] = { +1, 0, 0, -1 };
        int dj[] = { 0, -1, +1, 0 };

        solve(0, 0, m, n, ans, "", vis, di, dj);

        return ans;
    }
};


int main() {

    // Example input:
    // 1 0 0 0
    // 1 1 0 1
    // 1 1 0 0
    // 0 1 1 1

    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.findPath(maze, n);

    cout << "Possible paths:\n";
    for (string &p : paths) {
        cout << p << "\n";
    }

    return 0;
}
