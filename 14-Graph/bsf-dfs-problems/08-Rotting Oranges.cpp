#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // queue stores: ((row, col), time)
    queue<pair<pair<int, int>, int>> q;

    // visited matrix to track rotten/visited cells
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Step 1: push all initially rotten oranges into queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0}); // start time = 0
                vis[i][j] = 2;       // mark as visited/rotten
            }
        }
    }

    int time = 0;

    // direction vectors (up, right, down, left)
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};

    // Step 2: BFS traversal
    while (!q.empty())
    {

        int i = q.front().first.first;
        int j = q.front().first.second;
        int t = q.front().second;
        q.pop();

        // track maximum time taken
        time = max(time, t);

        // explore 4 directions
        for (int k = 0; k < 4; k++)
        {
            int row = i + delr[k];
            int col = j + delc[k];

            // valid cell + fresh orange + not visited
            if (row >= 0 && row < n && col >= 0 && col < m &&
                vis[row][col] != 2 && grid[row][col] == 1)
            {

                vis[row][col] = 2;  // mark visited
                grid[row][col] = 2; // convert to rotten

                // push into queue with incremented time
                q.push({{row, col}, t + 1});
            }
        }
    }

    // Step 3: check if any fresh orange remains
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return time;
}
int main()
{
}