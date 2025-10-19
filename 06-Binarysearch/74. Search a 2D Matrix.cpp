#include <bits/stdc++.h>
using namespace std;

// Approach 1: Start from top-right corner // approach is like stair case move left is large , if small move right 
// Time Complexity: O(m + n)
// We move left if current > target, down if current < target
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++; // move down: all left values are smaller
        else col--; // move left: all below values are larger
    }
    return false;
}

// Approach 2: Treat matrix as a sorted array, binary search
// Time Complexity: O(log(m*n))
// Map 1D index to 2D: mid/n is row, mid%n is col
bool searchMatrixBinary(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midval = matrix[mid / n][mid % n];
        if (midval == target) return true;
        else if (midval < target) left = mid + 1; // search right half
        else right = mid - 1; // search left half
    }
    return false;
}


int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    cout << "Approach 1: " << (searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    cout << "Approach 2: " << (searchMatrixBinary(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}