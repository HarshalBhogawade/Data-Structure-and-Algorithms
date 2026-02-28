#include <bits/stdc++.h>
using namespace std;

//tc : O(N) sc: O(N) vector used
//do dfs inorder traversal and get vector in sorted order 
void dfs(TreeNode *root, vector<int> &nums)
{
    if (!root)
        return;
    dfs(root->left, nums);
    nums.push_back(root->val);
    dfs(root->right, nums);
}

//perform the two pointer on the sorted array to get the pairs
bool findTarget(TreeNode *root, int k)
{
    vector<int> inorder;
    dfs(root, inorder);
    int i = 0;
    int j = inorder.size() - 1;
    while (i < j)
    {
        int sum = inorder[i] + inorder[j];
        if (sum == k)
        {
            return true;
        }
        else if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
int main()
{
}