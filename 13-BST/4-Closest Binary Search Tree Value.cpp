#include <bits/stdc++.h>
using namespace std;
void getdiff(Node *root, int k, int &absDiff)
{
    if (!root)
    {
        return;
    }
    getdiff(root->left, k, absDiff);
    absDiff = min(absDiff, abs(root->data - k));
    getdiff(root->right, k, absDiff);
}
int minDiff(Node *root, int K)
{
    int absDiff = INT_MAX;
    getdiff(root, K, absDiff);
    // Your code here
    return absDiff;
}
int main()
{
}