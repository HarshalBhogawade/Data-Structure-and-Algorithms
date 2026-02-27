#include<bits/stdc++.h>
using namespace std;
//time complexity : O(H) SC : O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true){
            int pval = p->val;
            int qval = q->val;
            int rootVal = root->val;

            //if both are smaller than root move to left
            if(pval < rootVal && qval < rootVal){
                root = root->left;

                //else both are greater than root , move right
            }else if(pval >rootVal && qval > rootVal){
                root = root->right;
            }else{

                //here p and q on left and right means , 
                //the current node is  the LCA 

                return root;
            }
        }
        return root;
}

int main(){
    
}