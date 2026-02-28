#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//tc : O(n) Sc : O(1) excluding  call stack
    TreeNode* traversal(vector<int>&a , int&i, int bound){
        //if array traversed or number greater than the accepted range / bound return null
        if(i==a.size() || a[i]>bound) return nullptr;
        //upper bound required here 
        TreeNode* root = new TreeNode(a[i++]); // create node
        root->left = traversal(a,i,root->val); // create upper bound as going left of curr node
        root->right = traversal(a,i,bound);// no need to create current node upper bound 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return traversal(preorder, i , INT_MAX); 

    }
};
int main(){


}