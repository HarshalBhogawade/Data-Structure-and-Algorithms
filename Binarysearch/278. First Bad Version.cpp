#include <bits/stdc++.h>
using namespace std;

// Mock API: In real problem, this is provided externally.
// Let's assume versions >= bad are bad.
int bad = 4; // Example: version 4 is the first bad version
bool isBadVersion(int version)
{
    return version >= bad;
}

// Function to find the first bad version
// Time Complexity: O(log n)
// Space Complexity: O(1)
int firstBadVersion(int n)
{
    int left = 1; // Versions are usually 1-indexed
    int right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid; // mid might be the first bad version
        }
        else
        {
            left = mid + 1; // first bad must be after mid
        }
    }
    return right; // or left, both are same here
}

int main()
{
    int n = 10; // total versions
    cout << "First bad version is: " << firstBadVersion(n) << endl;
    return 0;
}
