#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(N * M)
- Each cell is visited at most once.

Space Complexity: O(N * M) (worst case recursion stack)
- In worst case (all cells same), recursion depth can go up to N*M.
*/

void dfs(int sr, int sc, vector<vector<int>> &image, int color,
         int delRow[], int delCol[], int iniColor)
{
    // mark current cell with new color (acts as visited)
    image[sr][sc] = color;

    int n = image.size();
    int m = image[0].size();

    // explore 4 directions (up, right, down, left)
    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + delRow[i];
        int ncol = sc + delCol[i];

        // boundary check + same initial color condition
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == iniColor)
        {
            dfs(nrow, ncol, image, color, delRow, delCol, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int iniColor = image[sr][sc];

    // if new color is same as initial, no work needed
    if (iniColor == color)
        return image;

    // direction arrays for traversal
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // start DFS from given cell
    dfs(sr, sc, image, color, delRow, delCol, iniColor);

    return image;
}

int main()
{
    // no driver code
}