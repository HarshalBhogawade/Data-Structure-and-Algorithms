#include <bits/stdc++.h>
using namespace std;

// Function to perform level order traversal of a binary tree
vector<vector<int>> levelOrder(TreeNode *root)
{
    // Stores the final answer:
    // each inner vector represents one level of the tree
    vector<vector<int>> ans;

    // Queue for BFS (stores nodes level by level)
    queue<TreeNode *> q;

    // If tree is empty, return empty result
    if (!root)
        return ans;

    // Push root node to start BFS
    q.push(root);

    // Continue until all nodes are processed
    while (!q.empty())
    {

        // Number of nodes at the current level
        int size = q.size();

        // Stores values of nodes at current level
        vector<int> level;

        // Process all nodes of the current level
        for (int i = 0; i < size; i++)
        {

            // Get front node from queue
            TreeNode *node = q.front();
            q.pop();

            // Push left child if it exists
            if (node->left)
                q.push(node->left);

            // Push right child if it exists
            if (node->right)
                q.push(node->right);

            // Store current node's value
            level.push_back(node->val);
        }

        // Add current level to the final answer
        ans.push_back(level);
    }
    // Return level order traversal result
    return ans;
}
int main()
{
    // Driver code can be written here
}
