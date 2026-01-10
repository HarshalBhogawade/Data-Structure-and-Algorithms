#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a new node
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int n = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            level.push_back(node->val);
        }
        if (n % 2 == 0)
        {
            ans.push_back(level);
        }
        else if (n % 2 == 1)
        {
            reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        n++;
    }
    return ans;
}

int main() {}