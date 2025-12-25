#include<bits/stdc++.h>
using namespace std;
int maxDepth(Node* root) {
        if(root==nullptr){
            return 0;
        }
        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);

        return max(lheight , rheight) + 1;
}
int main(){

}