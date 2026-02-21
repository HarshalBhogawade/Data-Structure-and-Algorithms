bool pathcheck(TreeNode *root, int sum, int target)
{
    if (!root)
    {
        return false;
    }
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr) //if no left or right path completed
    {
        if (sum == target) // check if equal
        {
            return true;
        }
    }
    return pathcheck(root->left, sum, target) ||
           pathcheck(root->right, sum, target);
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }
    return pathcheck(root, 0, targetSum);
}