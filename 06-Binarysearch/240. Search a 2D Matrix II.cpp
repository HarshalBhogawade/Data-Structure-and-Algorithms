#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target value in a 2D matrix.
// The matrix has the following properties:
// - Integers in each row are sorted in ascending from left to right.
// - Integers in each column are sorted in ascending from top to bottom.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    // Start from the top-right corner and move left or down based on comparison
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Target found
        } else if (matrix[row][col] < target) {
            row++; // Move down to a larger value
        } else {
            col--; // Move left to a smaller value
        }
    }
    return false; // Target not found
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    // Search for the target in the matrix
    if (searchMatrix(matrix, target)) {
        cout << "Target found" << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}
