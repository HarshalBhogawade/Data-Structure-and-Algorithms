#include <bits/stdc++.h>
using namespace std;
// Find inorder successor (smallest node in right subtree)
TreeNode *findSucc(TreeNode *root)
{
    while (root->left)      // go to leftmost node
        root = root->left;
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return nullptr;     // base case: node not found

    // 🔍 search in right subtree
    if (root->val < key)
    {
        // deletion may change subtree root → reattach
        root->right = deleteNode(root->right, key);
    }
    // 🔍 search in left subtree
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        // 🎯 node found

        // case 1 & 2: node has 0 or 1 child
        if (!root->left)
            return root->right;   // replace with right child
        if (!root->right)
            return root->left;    // replace with left child

        // case 3: node has 2 children

        // find inorder successor (smallest in right subtree)
        TreeNode *succ = findSucc(root->right);

        // replace value with successor value
        root->val = succ->val;

        // delete duplicate successor node
        root->right = deleteNode(root->right, succ->val);
    }

    // return updated subtree root
    return root;
}
int main()
{
}