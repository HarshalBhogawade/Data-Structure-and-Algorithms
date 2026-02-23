#include<bits/stdc++.h>
using namespace std;

//traverse O(h+k) extra storage : O(h)
int ans = -1;
    void traverse(TreeNode* root , int &k){
        if(!root || k == 0) return;
        traverse(root->left, k);
        if(--k == 0){
            ans = root->val;
            return;
        }
        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return ans;
    }
int main(){

}