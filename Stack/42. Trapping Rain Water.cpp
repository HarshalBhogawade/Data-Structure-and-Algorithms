#include <bits/stdc++.h>
using namespace std;

// brute approach using two extra spaces for calculating leftmax and rightmax using two prefix and sufix array;
// tc: O(4N) Sc : O(2N)
int trap(vector<int> &height)
{

    int n = height.size();
    vector<int> premax(n); // stores leftmax for each curr elem
    vector<int> sufmax(n); // stores rightmax for each curr elem
    premax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        premax[i] = max(premax[i - 1], height[i]);
    }

    sufmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufmax[i] = max(sufmax[i + 1], height[i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int leftmax = premax[i];
        int rightmax = sufmax[i];
        if (height[i] < leftmax && height[i] < rightmax)
        {                                                // checks if height is smaller than lmax and rmax , because if not water unit becames -ve
            total += min(leftmax, rightmax) - height[i]; // calculates with min wall , coz water can only fill till small wall
        }
    }
    return total;
}

// optimized space used for prefix and suffix
// we use two pointers l and r for calculating lmax and rmax
// we only need one minimum for calculating water
// tc:O(N) Sc: O(1);
int trap2(vector<int> &height)
{
    int l = 0;                 // left pointer
    int r = height.size() - 1; // right pointer
    int leftmax = 0;           // max height seen so far from the left
    int rightmax = 0;          // max height seen so far from the right
    int total = 0;
    // Decide which side to process:
    // Water trapped depends on the smaller of leftmax and rightmax.
    if (height[l] <= height[r])
    {
        // Case: left side is lower or equal
        if (leftmax > height[l])
        {
            // Water can be trapped here
            total += leftmax - height[l];
        }
        else
        {
            // Update left maximum boundary
            leftmax = height[l];
        }
        l++; // move left pointer inward
    }
    else
    {
        // Case: right side is lower
        if (rightmax > height[r])
        {
            // Water can be trapped here
            total += rightmax - height[r];
        }
        else
        {
            // Update right maximum boundary
            rightmax = height[r];
        }
        r--; // move right pointer inward
    }
}

int main()
{
    vector<int>heig = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(heig);
    cout<<"Total water trapped : "<<ans;
    return 0;
}