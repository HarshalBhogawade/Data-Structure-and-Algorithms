#include <bits/stdc++.h>
using namespace std;

// tc O(N) sc O(1)

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int mincost = 0;

        // Start from 1 because we compare current balloon with previous one
        for (int i = 1; i < colors.size(); i++)
        {

            // Case 1: Consecutive balloons have the same color
            if (colors[i - 1] == colors[i])
            {
                while (i < colors.size() && colors[i - 1] == colors[i])
                {

                    // Remove the balloon with smaller neededTime
                    if (neededTime[i] <= neededTime[i - 1])
                        mincost += neededTime[i];
                    else
                        mincost += neededTime[i - 1];

                    // Keep the larger one for future comparison (same-color streak)
                    neededTime[i] = max(neededTime[i], neededTime[i - 1]);

                    i++; // move forward to next balloon
                }

                i--; // step back so the for-loop’s i++ keeps alignment
            }

            // Case 2: Check next color group (look ahead safely)
            else if (i + 1 < colors.size() && colors[i + 1] == colors[i])
            {
                while (i + 1 < colors.size() && colors[i + 1] == colors[i])
                {

                    // Remove balloon with smaller time
                    if (neededTime[i] <= neededTime[i + 1])
                        mincost += neededTime[i];
                    else
                        mincost += neededTime[i + 1];

                    // Keep the larger time for next comparison
                    neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
                    i++;
                }

                i--; // step back so for loop increments properly
            }
        }

        return mincost;
    }
    // alternate approach

    int minCost(string colors, vector<int> &neededTime)
    {
        // If there’s only one balloon, no need to remove anything
        if (colors.size() == 1)
        {
            return 0;
        }

        int i = 0;     // pointer to track the "kept" balloon
        int j = i + 1; // pointer to the next balloon
        int ans = 0;   // total minimum removal time

        // Traverse through all balloons
        while (j < colors.size())
        {

            // Case 1: Consecutive balloons have the same color
            if (colors[i] == colors[j])
            {

                // Remove the balloon with the smaller neededTime
                if (neededTime[i] <= neededTime[j])
                {
                    ans += neededTime[i]; // remove i-th balloon
                    i = j;                // keep j-th balloon for future comparison
                    j++;
                }
                else
                {
                    ans += neededTime[j]; // remove j-th balloon
                    j++;                  // move to next balloon
                }
            }

            // Case 2: Different colors → move both pointers forward
            else
            {
                i = j;
                j++;
            }
        }

        // Return total minimum time to remove balloons
        return ans;
    }
};

int main()
{
    Solution s;
    string colors = "abaac";
    vector<int> neededTime = {1, 2, 3, 4, 5};

    cout << s.minCost(colors, neededTime);
    return 0;
}
