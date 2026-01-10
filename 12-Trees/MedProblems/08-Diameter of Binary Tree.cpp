#include<bits/stdc++.h>
using namespace std;

//global var for diameter
int diameter = 0;

    int longest(TreeNode* root){

        //base case if null return 0
        if(root==nullptr){
            return 0;
        }

        int lheight = longest(root->left);
        int rheight = longest(root->right);

        diameter = max(diameter,lheight + rheight); //store max height at every node 

        return max(lheight,rheight)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        longest(root);
        return diameter;
}
int main(){

}