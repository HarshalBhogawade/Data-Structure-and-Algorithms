#include <bits/stdc++.h>
using namespace std;
int check(TreeNode *root, bool &isbal)
{
    if (root == nullptr)
        return 0;

    int left = check(root->left, isbal);
    int right = check(root->right, isbal);
    if (abs(right - left) > 1)
        isbal = false;
    return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
    bool isbal = true;
    check(root, isbal);
    return isbal;
}
int main()
{
}