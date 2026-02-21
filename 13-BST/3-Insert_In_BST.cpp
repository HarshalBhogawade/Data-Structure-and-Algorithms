#include<bits/stdc++.h>
using namespace std;
Node* insertINBst(Node* root , int val){
    if(!root) return new Node(val);
    Node* temp = root;
    Node* node = new Node(val);
    while(true){
        if(val < temp->val){
            if(!temp->left){
                temp->left = node;
                break;
            }
            temp = temp->left;
        }else{
            if(!temp->right){
                temp->right = node;
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}
int main(){

}