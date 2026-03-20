#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<char>> &grid, int rowArr[], int colArr[])
{
    grid[i][j] = '#'; // mark visited

    int n = grid.size();
    int m = grid[0].size();

    // explore 4 directions
    for (int k = 0; k < 4; k++)
    {
        int nrow = i + rowArr[k];
        int ncol = j + colArr[k];

        // boundary + unvisited land check
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
        {
            if (grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, grid, rowArr, colArr);
            }
        }
    }
}

// main function to count islands
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int rowArr[] = {-1, 0, +1, 0};
    int colArr[] = {0, +1, 0, -1};

    int cnt = 0;

    // traverse grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // found unvisited land
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid, rowArr, colArr); // mark full island
                cnt++; // count this island
            }
        }
    }

    return cnt;
}
int main(){
    
}