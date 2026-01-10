bool mirror(TreeNode *left, TreeNode *right)
{
    // both nodes are null
    if (left == NULL && right == NULL)
        return true;

    // only one is null
    if (left == NULL || right == NULL)
        return false;

    // values must match
    if (left->val != right->val)
        return false;

    // check mirror children
    return mirror(left->left, right->right) &&
           mirror(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    return mirror(root->left, root->right);
}