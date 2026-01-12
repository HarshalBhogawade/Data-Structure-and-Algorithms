#include <bits/stdc++.h>
using namespace std;
int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int mintime = 0;
    for (int i = 0; i < points.size() - 1; i++)
    {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[i + 1][0], y2 = points[i + 1][1];
        mintime += max(abs(x2 - x1), abs(y2 - y1));
    }
    return mintime;
    ;
}
int main()
{
}