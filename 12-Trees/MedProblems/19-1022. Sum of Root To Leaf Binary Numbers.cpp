#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalsum = 0;
    void pretraversal(TreeNode* root, int ans){
        if(!root) return;
        //process the node then do left n right traversal
         // convert 1(int) to '1'(char)
        ans = ans*2+(root->val);
        if(!root->left && !root->right){
            totalsum += ans;
        }

        pretraversal(root->left,ans);
        pretraversal(root->right,ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans= 0;
        pretraversal(root,ans);
        return totalsum;
    }
};
int main(){

}