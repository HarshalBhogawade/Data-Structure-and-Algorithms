#include <bits/stdc++.h>
using namespace std;

int maxsum = INT_MIN; // stores the maximum path sum found so far

int pathsum(TreeNode *root)
{
    // Base case: empty node contributes 0
    if (root == nullptr)
        return 0;

    // Recursively compute maximum path sum from left and right subtrees
    // Negative contributions are ignored because they reduce the path sum
    int leftsum = max(0, pathsum(root->left));
    int rightsum = max(0, pathsum(root->right));

    // Case 1: path passes through current node (left + root + right)
    // This path cannot be extended to parent, so update global answer
    maxsum = max(maxsum, leftsum + rightsum + root->val);

    // Case 2: path extends upward to parent
    // Only one side can be chosen to keep the path linear
    return root->val + max(leftsum, rightsum);
}

int maxPathSum(TreeNode *root)
{
    // Start DFS traversal to compute maximum path sum
    pathsum(root);
    return maxsum;
}
int main()
{
}