#include<bits/stdc++.h>
using namespace std;
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    // base case:
    // if tree ended OR we found one of the targets
    if(!root || root == p || root == q)
        return root;

    // search in left subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);

    // search in right subtree
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // if both sides returned non-null,
    // p and q are found in different branches
    // → current node is LCA
    if(left && right)
        return root;

    // otherwise return the side where a node was found
    return left ? left : right;
}
int main(){

}