#include<bits/stdc++.h>
using namespace std;
int Min(Node* root ){

    //min val will always be node val of the extreme left
    Node* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp->val;
}
//tc : O(logn) sc: O(1)

int Max(Node* root ){
    Node* temp = root;
        //min val will always be node val of the extreme right

    while(temp->right ){
        temp = temp->right;
    }
    return temp->val;
}
int main(){
    
}