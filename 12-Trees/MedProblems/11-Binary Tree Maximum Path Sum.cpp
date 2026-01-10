#include <bits/stdc++.h>
using namespace std;
int maxsum = INT_MIN;
int pathsum(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftsum = max(0, pathsum(root->left));
    int rightsum = max(0, pathsum(root->right));

    maxsum = max(maxsum, leftsum + rightsum + root->val);
    return max(leftsum, rightsum) + root->val;
}

int maxPathSum(TreeNode *root)
{
    pathsum(root);
    return maxsum;
}
int main()
{
}