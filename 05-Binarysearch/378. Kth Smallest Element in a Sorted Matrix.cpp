#include <bits/stdc++.h>
using namespace std;

// This solution flattens the matrix into a single vector,
// sorts it, and returns the k-th smallest element.
// Time Complexity: O(n^2 log n), where n is the number of rows (or columns).
// Space Complexity: O(n^2), for storing all elements in a separate vector.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> mat; // Flattened matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                mat.push_back(matrix[i][j]); // Collect all elements
            }
        }
        sort(mat.begin(), mat.end()); // Sort all elements
        return mat[k - 1]; // Return k-th smallest (1-based index)
    }
};

int main() {
    // Example matrix (each row and column is sorted)
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    Solution sol;
    cout << sol.kthSmallest(matrix, k) << endl; // Output: 13
    return 0;
}